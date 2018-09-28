library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.numeric_std.all;
use IEEE.std_logic_unsigned.all;

ENTITY somador IS
PORT ( a, b : IN STD_LOGIC_VECTOR(7 DOWNTO 0);
		s : out STD_LOGIC_VECTOR(7 DOWNTO 0));
END somador;

ARCHITECTURE estrutura OF somador IS
BEGIN
	s <= a + b;
END estrutura;
