/*  TRABALHO 04 da NP2
	Aluno: ADRIEL SCHMITZ
	Disciplina: PROGRAMAÇÃO 1
	Professor: DOGLAS ANDRÉ FINCO
*/
import java.util.*;

public class Teste{
	public static void main(String[] args){
		Scanner ler = new Scanner(System.in);
		Blog blogueiro = new Blog();
		boolean flag = true, flag_menu = true;
		int opcao=0, indice;

		while(flag){
			while(flag_menu){
				System.out.print(	"\n\nBLOG: O que voce quer fazer?\n" +
									"1  - Novo post de noticia\n" +
									"2  - Nova resenha de produto\n" +
									"3  - Novo post de outros assuntos\n" +
									"4  - Listar todas as postagens\n" +
									"5  - Curtir uma postagem\n" +
									"6  - Nao curtir uma postagem\n" +
									"10 - Sair\n"+
									"Escolha uma opcao → " );
				try{
					opcao = ler.nextInt();
					flag_menu = false;
				}catch(InputMismatchException error){
					System.out.println("\n**ERROR** Informe apenas inteiros!");
				}
			}
			flag_menu = true;
			ler.nextLine();
			switch(opcao){
				case 1:
					News noticias = new News();
					blogueiro.readData(noticias);
					break;
				case 2:
					ProductReview outros = new ProductReview();
					blogueiro.readData(outros);
					break;
				case 3:
					Post postagem = new Post();
					blogueiro.readData(postagem);
					break;
				case 4:
					blogueiro.showAll();
					break;
				case 5:
					blogueiro.showAll();
					System.out.print("Qual postagem deseja Curtir?(informe o id) → ");
					try{
						indice =  ler.nextInt();
						blogueiro.getPostsArrayList(indice-1).like();// acessa a publicação do indice desejado
					}catch(InputMismatchException | IndexOutOfBoundsException error){
						System.out.println("\n**ERROR** Informe apenas inteiros!");
					}
					ler.nextLine();
					break;
				case 6:
					blogueiro.showAll();
					System.out.print("Qual postagem deseja Descurtir?(informe o id) → ");
					try{
						indice =  ler.nextInt();
						blogueiro.getPostsArrayList(indice-1).deslike();
					}catch(InputMismatchException | IndexOutOfBoundsException error){
						System.out.println("\n**ERROR** Informe apenas inteiros!");
					}
					ler.nextLine();
					break;
				case 10:
					flag = false;
					break;
				default:
					System.out.println("OPCAO INVALIDA!");
					break;
			}
		}
	}
}
