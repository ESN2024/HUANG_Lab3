/*
 * "Hello World" example.
 *
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example
 * designs. It runs with or without the MicroC/OS-II RTOS and requires a STDOUT
 * device in your system's hardware.
 * The memory footprint of this hosted application is ~69 kbytes by default
 * using the standard reference design.
 *
 * For a reduced footprint version of this template, and an explanation of how
 * to reduce the memory footprint for a given application, see the
 * "small_hello_world" template.
 *
 */

#include <stdio.h>
#include <system.h>
#include <altera_avalon_pio_regs.h>
#include <altera_avalon_timer_regs.h>
#include <sys/alt_irq.h>  //interrupt header

 alt_u8  i=0;
 alt_u32 timer_isr_context;

  void Timer_ISR_Interrupt(void* timer_isr_context, alt_u32 id)
  {
  i = 1;
  IOWR_ALTERA_AVALON_TIMER_STATUS(0x0,~ALTERA_AVALON_TIMER_STATUS_TO_MSK);
  }


void Timer_initial(void)
{

 void* isr_context_ptr = (void*) &timer_isr_context;


//PERIODH | PERIODL = 1s*50M - 1 = 49999999 = 0x05F5_EOFF
 IOWR_ALTERA_AVALON_TIMER_PERIODH(0x0, 0x02FA);
 IOWR_ALTERA_AVALON_TIMER_PERIODL(0x0, 0xF07F);

IOWR_ALTERA_AVALON_TIMER_CONTROL(0x0,
 ALTERA_AVALON_TIMER_CONTROL_START_MSK |
 ALTERA_AVALON_TIMER_CONTROL_CONT_MSK |
 ALTERA_AVALON_TIMER_CONTROL_ITO_MSK);

 alt_ic_isr_register(
 0,
 1,
 Timer_ISR_Interrupt, //
 isr_context_ptr,
 0x0); //flags£¬
 }

int main()
{
 // printf("Hello from Nios II!\n");

  int counter=0;
  int m3,m2,m1;
  int data ;
  Timer_initial();

  while (1){

 /*   1
  
         usleep(100000) ;
         if (counter==9){
        	    counter=0;
                         }
         else
                 {counter++;}
           
                  
    */


 // /*   2
  
         usleep(1000000) ;
         if (counter==999){
        	    counter=0;
                         }
         else
                 {counter++;}
           
                  
   // */



/*   3
  if( i == 1 ) {

         if (counter==999){
        	    counter=0;
                         }
         else
                 {counter++;}
             i=0;
                  }
   */
                  
                  
                  
                  
                  
                  
                  
        m3 = counter/100;
        m2=  (counter/10)%10;
        m1=  counter%10;
        data = (m3<<8) + (m2<<4) + m1;
         IOWR_ALTERA_AVALON_PIO_DATA(COUNTER_BASE, data); //wr led

  }


  return 0;
}








