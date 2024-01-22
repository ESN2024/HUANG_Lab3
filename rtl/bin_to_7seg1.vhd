library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity bin_to_7seg1 is
port (SW : in std_logic_vector (3 downto 0);
HEX0 : out std_logic_vector (7 downto 0));
end entity bin_to_7seg1;


architecture top_arch of bin_to_7seg1 is
begin
-- Decoder process goes here��?
	decoder: process(SW)
		begin
			case SW is
				when "0000" => HEX0 <= "10111111";		--0
                when others => HEX0 <= "11111111";
		end case;
	end process decoder;
end architecture top_arch;