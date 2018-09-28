import java.util.*;
import java.text.DecimalFormat;

public class listaExercicios3{
	public static void main(String[] args){
		Scanner ler = new Scanner(System.in);
		int entrada;
		int i=0, soma=0, fatorial=1, flag=1;
		while(flag == 1){
			System.out.print("Informe um nº entre [1] a [7] ou [0] para sair: ");
			entrada = ler.nextInt();
			switch(entrada){
				case 0:
					flag = 0;
					break;
				case 1:
					for(i=120; i<=280; i++)
						System.out.print(i + " ");
					flag = 1;
					break;
				case 2:
					for(i = 1; i<=500; i++)
						soma += i;
					System.out.println("A soma entre 1 a 500 eh: " + soma);
					flag = 1;
					break;
				case 3:
					for(i=50; i<=150; i++)
						if(i%3 == 0)
							System.out.print(i + " ");
					System.out.print("\n");
					flag = 1;
					break;
				case 4:
					for(i=1; i<=10; i++){
						fatorial *= i;
						System.out.println("Fatorial de["+ i +"] eh: " + fatorial);
					}
					flag = 1;
					break;
				case 5:
					for(i=1; i<=40; i++){
						fatorial *= i;
						System.out.println("Fatorial de["+ i +"] eh: " + fatorial);
					}
					System.out.println("A variável do tipo inteiro (32 bytes) nao suporta o resultado!");
					flag = 1;
					break;
				case 6:
					int a=0, b=1;
					System.out.print("0, 1");
					for(i=0; i<100; i++){
						soma = a+b;
						a =b;
						b = soma;
						if(soma > 100)
							break;
						System.out.print(", " + soma);
					}
					System.out.print("\n");
					flag = 1;
					break;
				case 7:
					int op_7_ativa = 1, n;
					while(op_7_ativa == 1){
						n = ler.nextInt();
						if(n == 1)
							break;
						for(i=0; i<=n; i++){
							if(n%2 == 0)
								n /= 2;
							else
								n = (3*n)+1;
							System.out.print(n + " -> ");
						}
						System.out.println("");
					}
					flag = 1;
					break;
				default:
					System.out.print("Informe um número entre 1 a 7!\n");
					flag = 1;
					break;
			}
		}
	}
}