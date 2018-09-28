import java.util.*; 
public class Teste{
	public static void main(String[] args){
		Scanner ler = new Scanner(System.in);
		Verifica vet = new Verifica();
		Boolean flag_1 = true, flag_1_2 = true;
		int[] vetor = new int[10];
		int i, a, b;
		
		while(flag_1){
			try{
				for(i=0; i<10; i++){
					System.out.print("Informe um valor para o " + (i+1) + "º vetor → ");
					vetor[i] = ler.nextInt();
				}
				vet.somaInteiros(vetor, 10, 0, 9);
				flag_1 = false;
			}catch(Exception erro){
				System.out.println("**Erro** Preencha novamente os valores!");
			}finally{
				ler.nextLine();
			}
		}
		
		flag_1 = true;
		while(flag_1_2){
			System.out.print("Quer somar de qual vetor até qual? → ");
			try{
				a = ler.nextInt()-1;//pra acessar o indice certo no vetor, um a menos que o usuário escolher...
				b = ler.nextInt()-1;
				System.out.println("SOMA: " + vet.somaInteiros(vetor, 10, a, b));
				flag_1_2 = false;
			}catch(Exception erro){
				System.out.println("**Error** Valor fora do intervado!");
			}
		}
		System.out.println("Programa Encerrado");
	}
}