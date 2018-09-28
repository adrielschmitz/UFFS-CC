/*  2º trabalho da NP1 da desciplina de Programação I
	Tema: O sistema da bodega
	Aluno: ADRIEL SCHMITZ
	Professor: DOGLAS ANDRÉ FINCO
*/
import java.util.*;
public class Teste{
	public static void main(String[] args){
		Scanner ler = new Scanner(System.in);
		// VARIÁVEIS AUXILIARES
		int opcao_menu, opcao_bebida, qtd_venda, continuar_vendendo, continuar_comprando, qtd_compra;
		boolean flag = true, flag_vender, flag_comprar;

		// DADOS DA EMPRESA -------------------------------------------------------------------------------------------
		Empresa empresa = new Empresa("ßød€ga Dø Cadú", "122345-x");

		// DADOS DAS BEBIDAS ------------------------------------------------------------------------------------------					
		 Bebida bebida = new Bebida("Cerveja", "12.5%", "390 ml", 8, 20); // bebida 1
		 empresa.armazenaBebida(bebida);
		 bebida = new Bebida("Energético", "0.0%", "280 ml", 12, 30); // bebida 2
		 empresa.armazenaBebida(bebida);
		 bebida = new Bebida("Pinga", "110%", "100 lm", 1.50, 40); // bebida 3
		 empresa.armazenaBebida(bebida);
		//-------------------------------------------------------------------------------------------------------------
		while(flag){
			empresa.menu();
			opcao_menu = ler.nextInt();
			switch(opcao_menu){
				case 1:
					empresa.imprimirEmpresa();
					break;
				case 2:
					Funcionarios bodegueiro = new Funcionarios("Carlos Eduardo", "Gerente Master", 10000, "003081812-55", "Rua: Fantasia Nº 1234", "(41) 98803-9441");
					empresa.Contrata(bodegueiro);
					bodegueiro = new Funcionarios("Artur Eduardo", "Faxineiro", 867.00, "003081812-55", "Rua: Fantasia Nº 5678", "(41) 98803-9442");
					empresa.Contrata(bodegueiro);
					bodegueiro = new Funcionarios("Henrique Eduardo", "Faxineiro", 867.00, "003081812-55", "Rua: Fantasia Nº 9101", "(41) 98803-9443");
					empresa.Contrata(bodegueiro);
					System.out.println("\n\t\t 3 FUNCIONÁRIOS CONTRATADOS!");
					break;
				case 3:
					empresa.imprimirFuncionarios();
					break;
				case 4:
					flag_vender = true;
					while(flag_vender){
						empresa.mostrarBebidas();
						System.out.printf("\t\t VAI TOMAR O QUE PATRÃO?\n\t\t → " );
						opcao_bebida = ler.nextInt();
						System.out.printf("\t\t QUANTOS(AS) HOJE? → ");
						qtd_venda = ler.nextInt();
						if(empresa.confereEstoque(qtd_venda, opcao_bebida)){
							empresa.Vender(qtd_venda, opcao_bebida);
						}else{
							System.out.println("\t\tBAA, NAO TENHO ISSO TUDO EM ESTOQUE!");
						}
						System.out.printf("\t\tCONTINUAR COMPRANDO? Sim[1] | Nao[2]\n\t\t→ ");
						continuar_vendendo = ler.nextInt();
						if(continuar_vendendo == 2){
							flag_vender = false;
						}
					}
					break;
				case 5:
					flag_comprar = true;
					while(flag_comprar){
						System.out.printf("\t\tQUAL BEBIDA DESEJA COMPRAR MAIS?\n\t\t[1] Cerveja\n\t\t[2] Energético\n\t\t[3] Pinga\n\t\t→ ");
						opcao_bebida = ler.nextInt();
						System.out.printf("\t\tQUANTIDADE\n\t\t→ ");
						qtd_compra = ler.nextInt();
						empresa.Comprar(qtd_compra, opcao_bebida);
						System.out.printf("\t\tCONTINUAR COMPRANDO? Sim[1] | Nao[2]\n\t\t→ ");
						continuar_comprando = ler.nextInt();
						if(continuar_comprando == 2){
							flag_comprar = false;
						}
					}
					break;
				case 6:
					Clientes cliente = new Clientes("Jandira da Cunha", "11122233", true); // cliente 1
					empresa.adicionaClientes(cliente);
					cliente = new Clientes("José da Silva", "44455566", true); // cliente 2
					empresa.adicionaClientes(cliente);
					cliente = new Clientes("Maicon da Silva", "77788899", false); // cliente 3
					empresa.adicionaClientes(cliente);
					System.out.println("\n\t\t 3 CLIENTES CADASTRADOS!");
					break;
				case 7:
					empresa.mostraClientes();
					break;
				case 8:
					flag = false;
					break;
				default:
					System.out.println("\t\tOPÇÃO INVÁLIDA!");
					break;
			}
		}	
	}
}