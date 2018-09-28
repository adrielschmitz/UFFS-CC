import java.util.Scanner;
public class ExemploScanner{
	public static void main(String[] args){
		Scanner ler = new Scanner(System.in);

		System.out.print("Digite seu nome completo: ");
		String nome = ler.nextLine();

		System.out.print("Digite seu signo: ");
		String signo = ler.next();

		System.out.print("Digite seu peso: ");
		double peso = ler.nextDouble();

		System.out.print("Digite seu número da sorte: ");
		int nsorte = ler.nextInt();

		System.out.println("\nOlá " + nome + "!");
		System.out.println("Seu número da sorte é " + nsorte + ".");
		System.out.println("Voce pesa " + peso + " kg.");
		System.out.println("Seu signo é " + signo + ".");
	}
}