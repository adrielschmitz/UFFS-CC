import java.util.*;

public class Programa{
	public static void main(String[] args){
		Scanner ler = new Scanner(System.in);
		List<Publicacao> lista_mensal = new ArrayList<>();
		List<PublicacaoSemanal> lista_semanal = new ArrayList<>();
		Editora editora_padrao = new Editora("Ltda. Schmitz", "35256626-X");
		int menu, op_publicacao;
		Boolean flag = true;

		while(flag){
			System.out.print("\n\tInforme uma opção" +
							 "\n1. Adicionar Publicacao" +
							 "\n2. Visualizar Publicacao Mensal" +
							 "\n3. Visualizar Publicacao Semanal" +
							 "\n0. Sair\n→ ");
			menu = ler.nextInt();
			switch(menu){
				case 1:
					System.out.print("\n\tQual publicação voce deseja?"+
									 "\n1. Mensal"+
									 "\n2. Semanal"+
									 "\n0. Voltar ao Menu Inicial\n→ " );
					op_publicacao = ler.nextInt();
					switch(op_publicacao){
						case 1:
							Publicacao mensal = new Publicacao("SEU JAVA MENSAL", 70.50);
							mensal.editora = editora_padrao;
							lista_mensal.add(mensal);
							System.out.println("\n\tPUBLICAÇÃO ADICIONADA!");
							break;
						case 2:
							PublicacaoSemanal semanal = new PublicacaoSemanal("SEU JAVA SEMANAL", 10.90);
							semanal.editora = editora_padrao;
							lista_semanal.add(semanal);
							System.out.println("\n\tPUBLICAÇÃO ADICIONADA!");
							break;
						case 0:
							break;
						default:
							System.out.print("\n\nOpção Inválida\n");
							break;
					}
					break;
				case 2:
					System.out.print("\n\t-----PUBLICAÇÃO MENSAL-----");
					for(Publicacao m : lista_mensal){
						m.imprimirDados();
					}
					System.out.print("\t----------------------------");
					break;
				case 3:
					System.out.print("\n\t-----PUBLICAÇÃO SEMANAL-----");
					for(PublicacaoSemanal s : lista_semanal){
						s.imprimirDados();
					}
					System.out.print("\t----------------------------");
					break;
				case 0:
					flag = false;
					break;
				default:
					System.out.println("\n\nOpção Inválida\n");
					break;

			}
		}
	}
}