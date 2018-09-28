import java.util.Scanner;
public class ExemploArray{
	public static void main(String[] args){
		int[] vetor = {10, 20, 30, 0, 2}; //iniciando o vetor com elementos
		int i;
		vetor = new int[5]; //um vetor com 5 posiçoes na memória

		for(i=0; i<vetor.length; i++)
			System.out.println("i[" + i + "] = " + vetor[i]);
	}
}