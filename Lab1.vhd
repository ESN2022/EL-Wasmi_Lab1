library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity Lab1 is
	port (
		clk                         : in  std_logic;             --                        clk.clk
		leds: out std_logic_vector(7 downto 0);                    --   leds_external_connection.export
		push : in  std_logic                    := '0';             --   push_external_connection.export
		switch: in  std_logic_vector(3 downto 0) := (others => '0');  -- switch_external_connection.export
		reset                     : in  std_logic 
		);
	
end entity Lab1;  
	 
	 architecture rtl of Lab1 is
	 component Lab1_sys is
        port (
            clk_clk                           : in  std_logic                    := 'X';             -- clk
            leds_external_connection_export   : out std_logic_vector(7 downto 0);                    -- export
            push_external_connection_export   : in  std_logic                    := 'X';             -- export
            switch_external_connection_export : in  std_logic_vector(3 downto 0) := (others => 'X');  -- export
				reset_reset_n                     : in  std_logic
		  );
    end component Lab1_sys;
	 
begin
    u0 : component Lab1_sys
        port map (
            clk_clk                           => clk,                           --                        clk.clk
            leds_external_connection_export   => leds,   --   leds_external_connection.export
            push_external_connection_export   => push,   --   push_external_connection.export
            switch_external_connection_export => switch,  -- switch_external_connection.export
				reset_reset_n							 => reset
        );
end architecture rtl;
