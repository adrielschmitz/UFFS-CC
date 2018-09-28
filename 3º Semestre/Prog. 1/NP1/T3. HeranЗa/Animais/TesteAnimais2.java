import java.util.*;
public class TesteAnimais2{
	public static void main(String[] args){
		Scanner ler = new Scanner(System.in);
		List<Animal> lista_animal = new ArrayList<>();
		List<Peixe> lista_peixes = new ArrayList<>();
		List<Mamifero> lista_mamiferos = new ArrayList<>();
		int menu, qtd, comprimento, patas;
		String nome, cor, ambiente, caracteristicas, alimento;
		double velocidade;
		boolean flag = true;

		while(flag){
			System.out.printf(	"\n\tESCOLHA UMA OPÇÃO..." +
								"\n[1] Animal sem especificação" +
								"\n[2] Peixe" +
								"\n[3] Mamífero" +
								"\n[0] Sair" +
								"\n→ " );
			menu = ler.nextInt();
			switch(menu){
				case 1:
					System.out.printf("Quantos animais deseja adicionar a lista?\n→ ");
					qtd = ler.nextInt();
					for(int i=0; i<qtd; i++){
						System.out.println("\nANIMAL " + (i+1));
						System.out.printf("Qual o nome do animal? → ");
						nome = ler.next();
						System.out.printf("Qual a cor do animal? → ");
						cor = ler.next();
						System.out.printf("Qual o seu ambiente? → ");
						ambiente = ler.next();
						System.out.printf("Qual o seu comprimento? → ");
						comprimento = ler.nextInt();
						System.out.printf("Qual sua velocidade? → ");
						velocidade = ler.nextDouble();
						System.out.printf("Quantas patas? → ");
						patas = ler.nextInt();
						Animal animal = new Animal(nome, cor, ambiente, comprimento, velocidade, patas);
						lista_animal.add(animal);
					}
					System.out.println("\n----- ANIMAIS -----");
					for(Animal a : lista_animal){
						a.dados();
					}
					break;
				case 2:
					System.out.printf("Quantos animais deseja adicionar a lista?\n→ ");
					qtd = ler.nextInt();
					for(int i=0; i<qtd; i++){
						System.out.println("\nANIMAL " + (i+1));
						System.out.printf("Qual o nome do animal? → ");
						nome = ler.next();
						System.out.printf("Qual a cor do animal? → ");
						cor = ler.next();
						System.out.printf("Qual o seu ambiente? → ");
						ambiente = ler.next();
						System.out.printf("Qual o seu comprimento? → ");
						comprimento = ler.nextInt();
						System.out.printf("Qual sua velocidade? → ");
						velocidade = ler.nextDouble();
						System.out.printf("Quantas patas? → ");
						patas = ler.nextInt();
						System.out.printf("Quais suas caracteristicas? → ");
						caracteristicas = ler.next();
						Peixe animal_p = new Peixe(nome, cor, ambiente, comprimento, velocidade, patas, caracteristicas);
						lista_peixes.add(animal_p);
					}
					System.out.println("\n----- PEIXES -----");
					for(Peixe p : lista_peixes){
						p.dados();
					}
					break;
				case 3:
					System.out.printf("Quantos animais deseja adicionar a lista?\n→ ");
					qtd = ler.nextInt();
					for(int i=0; i<qtd; i++){
						System.out.println("\nANIMAL " + (i+1));
						System.out.printf("Qual o nome do animal? → ");
						nome = ler.next();
						System.out.printf("Qual a cor do animal? → ");
						cor = ler.next();
						System.out.printf("Qual o seu ambiente? → ");
						ambiente = ler.next();
						System.out.printf("Qual o seu comprimento? → ");
						comprimento = ler.nextInt();
						System.out.printf("Qual sua velocidade? → ");
						velocidade = ler.nextDouble();
						System.out.printf("Quantas patas? → ");
						patas = ler.nextInt();
						System.out.printf("Qual seu alimento? → ");
						alimento = ler.next();
						Mamifero animal_m = new Mamifero(nome, cor, ambiente, comprimento, velocidade, patas, alimento);
						lista_mamiferos.add(animal_m);
					}
					System.out.println("\n----- MAMÍFEROS -----");
					for(Mamifero m : lista_mamiferos){
						m.dados();
					}
					break;
				case 0:
					flag = false;
					break;
				default:
					System.out.println("\tOpção nao permitida!");
					break;
			}
		}
	}
}