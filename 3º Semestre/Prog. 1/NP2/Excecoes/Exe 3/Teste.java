import java.util.*;

public class Teste{
	public static void main(String[] args){
		Scanner ler = new Scanner(System.in);
		Matematica vet = new Matematica();
		int vetor[] = new int[1];
		int n=0;
		try{
			System.out.print("Informe o N → ");
			n = vet.verifica(ler.nextInt());
				ler.nextLine();
			vetor = new int[n];
			for(int i=0; i<n; i++){
				System.out.print("Informe o valor do " +(i+1)+ "º vetor → ");
				vetor[i] = ler.nextInt();
						   ler.nextLine();
			}
		}catch(InputMismatchException error){
			System.out.println("**Error**\nInforme apenas inteiros!!");
		}catch(NegativeArraySizeException error2){
			System.out.println("**Error**\nFoi informado um número negativo!");
			int vet2[] = new int[1];
			vet2[0] = 123;
			System.out.println("Vetor de erro = " + vet2[0]);
		}finally{
			for(int i=0; i<n; i++){
				System.out.println("Vetor["+(i+1)+"] = " + vetor[i]);
			}
		}
	}
}