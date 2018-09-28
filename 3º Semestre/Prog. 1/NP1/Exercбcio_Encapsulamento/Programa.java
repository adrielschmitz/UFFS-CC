import java.util.*;

public class Programa{
	public static void main(String[] args){
		Scanner ler = new Scanner(System.in);
		List<Pessoa> lista_pessoas = new ArrayList<>();//instancia uma lista do tipo Pessoas
		Random aleatorio = new Random();
		String nome;
		int menu;
		float peso;
		boolean flag = true;

		while(flag){
			System.out.println("\t----------MENU--------");
			System.out.println("\t [1] Adicionar Pessoa");
			System.out.println("\t [2] Mostrar Pessoas Cadastradas");
			System.out.println("\t [0] Sair");
			System.out.print("\t → ");
			menu = ler.nextInt();
			switch(menu){
				case 0:
					flag = false;
					break;
				case 1:
					Pessoa pessoas = new Pessoa(); //instancia uma nova variável (como se fosse o maloc em C)
					
					System.out.print("\t Nome: ");
					nome = ler.next();
					pessoas.setNome(nome);
					pessoas.setIdade(aleatorio.nextInt(10)+25);
					System.out.print("\t Peso: ");
					peso = ler.nextFloat();
					pessoas.setPeso(peso);

					lista_pessoas.add(pessoas); //passa os atributos da variável pessoa para o espaço que foi alocado na lista
					break;
				case 2:
					for(int i=0; i<lista_pessoas.size(); i++){ // função size verifica até a lista tem elementos
						Pessoa aux = lista_pessoas.get(i); // cria uma variável do mesmo tipo da classe da lista e faz ela receber o conteúdo da lista na posição em que está o i
						System.out.println("→ " +aux.getNome()+ " tem " 
												+aux.getIdade()+ " anos" + " e pesa " 
												+aux.getPeso()+ " kg!"); 
					}
					break;
				default:
					System.out.println("***Opção inválida!***");
					break;
			}
		}
	}
}