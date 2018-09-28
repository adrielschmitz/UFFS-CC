import java.util.*; 

public class Teste{
	public static void main(String[] args){
		Scanner ler = new Scanner(System.in);
		Matematica math = new Matematica();
		double a = 0, b = 0, resultado = 0;
		int opcao = 0;
		boolean flag = true, flag_escolha = true, flag_entrada = true;

		while(flag){
			while(flag_escolha){
				System.out.print(	"\nQual operação deseja?\n"
									+"1 - Soma\n"
									+"2 - Subtração\n"
									+"3 - Divisão\n"
									+"4 - Multiplicação\n"
									+"0 - Sair\n"
									+"Opção → " );
				try{
					opcao = ler.nextInt();
					if(opcao < 5){
						flag_escolha = false;
					}else{
						System.out.println("\nInforme números apenas entre 0 a 5!");
						flag_escolha = true;
					}
				}catch(InputMismatchException error){
					System.out.println("\n\t**ERROR** Informe apenas inteiros!");
					ler.nextLine();
					flag_escolha = true;
				}
			}
			if(opcao != 0){
				flag_escolha = true;
				while(flag_entrada){
					try{
						math.testaDados();
						flag_entrada = false;
					}catch(ParamZeroException error){//exceção criada na classe math
						System.out.println("\n\t**ERROR** Informe números diferentes de 0!!\n");
					}			
				}
			}
			flag_entrada = true;
			switch(opcao){
				case 0:
					flag = false;
					break;
				case 1:
					try{
						System.out.println("\nRESULTADO: " + math.somar());
					}catch(ResultadoZeroException error){
						System.out.println("Resultado igual a zero, operação cancelada...");
					}
					break;
				case 2:
					try{
						System.out.println("\nRESULTADO: " + math.subtrair());
					}catch(ResultadoZeroException error){
						System.out.println("Resultado igual a zero, operação cancelada...");
					}
					break;
				case 3:
					try{
						System.out.println("\nRESULTADO: " + math.dividir());
					}catch(ResultadoZeroException error){
						System.out.println("Resultado igual a zero, operação cancelada...");
					}
					break;
				case 4:
					try{
						System.out.println("\nRESULTADO: " + math.multiplicar());
					}catch(ResultadoZeroException error){
						System.out.println("Resultado igual a zero, operação cancelada...");
					}
					break;
				default:
					System.out.println("**ERROR** INFORME OPÇÃOES ENTRE 0 A 4!");
			}
		}
	}
}