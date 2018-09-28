import java.util.*;

public class programa{
	public static void main(String[] args){
		int a, b, c;
		Scanner ler = new Scanner(System.in);
		System.out.printf("Informe os valor de A, B e C: ");
		a = ler.nextInt();
		b = ler.nextInt();
		c = ler.nextInt();
		Bhaskara bhaskara = new Bhaskara(a, b, c);
		bhaskara.imprime_raiz();
	}
}