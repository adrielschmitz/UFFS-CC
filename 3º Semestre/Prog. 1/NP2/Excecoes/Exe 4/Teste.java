//ArrayIndexOutOfBoundsException:
//Erro dado quando é informado uma posição que nao exista no vetor||lista
import java.util.*;
class Teste{
	public static void main(String[] args) {
		Scanner ler = new Scanner(System.in);
		int vet[] = new int[10];
		boolean flag = true, flag_n = true;
		int entrada, n = 11;
		while(flag){
			if(n > 10){
				System.out.println("\tTamanho do vetor: 10\n"
							   + "\tPosição informada propositalmente: 11\n" );
			}
			try{
				for(int i=0; i < n; i++){
					vet[i] = i+1;
					System.out.println("Vetor[" +(i)+ "] = " + vet[i]);
				}
				flag = false;
			}catch(ArrayIndexOutOfBoundsException e){
				System.out.println("\n**Erro** Índice informado fora do intervalo!");
				System.out.print("\nInforme uma entrada <= 10 → ");
				n = ler.nextInt();
				flag = true;
			}
		}
	}
}