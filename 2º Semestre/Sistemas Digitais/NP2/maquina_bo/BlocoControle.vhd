library ieee;
use ieee.std_logic_1164.all;

ENTITY maquina IS
   PORT (Reset, clk, c : IN STD_LOGIC;
             s, a : IN STD_LOGIC_VECTOR(7 DOWNTO 0);
             d : OUT STD_LOGIC);
END maquina;

ARCHITECTURE estrutura OF maquina IS
	TYPE state_type IS (INICIO, ESPERA, ACUM, LIBERA);
	SIGNAL state: state_type;
	COMPONENT bo IS
		PORT (clk, Ctotal, Rtotal : IN STD_LOGIC;
		         s, a : IN STD_LOGIC_VECTOR(7 DOWNTO 0);
		         menor : OUT STD_LOGIC	);
	END COMPONENT;
	COMPONENT bc IS
	PORT (Reset, clk, c, menor : IN STD_LOGIC;
	          d, Ctotal, Rtotal : OUT STD_LOGIC);
	END COMPONENT;

	SIGNAL Ctotal, Rtotal, menor : STD_LOGIC;
	BEGIN
		b_operativo: bo PORT MAP (clk, Ctotal, Rtotal, s, a, menor);
		b_controle: bc PORT MAP (Reset, clk, c, menor, d, Ctotal, Rtotal);

	PROCESS (clk, Reset)
		BEGIN
			if(Reset = '1') THEN  state <= INICIO;
			ELSIF (clk'EVENT AND clk = '1') THEN
			   CASE state IS
				WHEN INICIO =>
					state <= ESPERA;
				WHEN ESPERA =>
					IF (c = '1') THEN
						state <= ACUM;
					ELSIF (menor = '0') THEN
						state <= LIBERA;
					ELSE
						state <= ESPERA;
					END IF;
				WHEN ACUM =>
					state <= ESPERA;
				WHEN LIBERA =>
					state <= INICIO;
			END CASE;
		     END IF;
		END PROCESS; 
	PROCESS (state)
		BEGIN
			CASE state IS
				WHEN INICIO =>
					d <= '0';
					Rtotal <= '1';
					Ctotal <= '0';
				WHEN ESPERA =>
					d <= '0';
					Rtotal <= '0';
					Ctotal <= '0';
				WHEN ACUM =>
					d <= '0';
					Rtotal <= '0';
					Ctotal <= '1';
				WHEN LIBERA =>
					d <= '1';
					Rtotal <= '0';
					Ctotal <= '0';
			END CASE;
		END PROCESS; 	
end ARCHITECTURE;
