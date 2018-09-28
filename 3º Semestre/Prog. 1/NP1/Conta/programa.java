import java.util.*;

public class programa{
	public static void main(String[] args){
		double valor_deposito, valor_saque;
		Scanner ler = new Scanner(System.in);
		Conta minhaConta = new Conta();
		int opcao = 0, flag_2, continuar_saque, flag_3, continuar_deposito;
		boolean flag = true, flag_menu = true;

		System.out.print("Digite o nome do titular dessa conta: ");
		minhaConta.dono = ler.nextLine();
		System.out.print("Informe o número do titular da conta: ");
		minhaConta.numero = ler.nextInt();
		System.out.print("Informe seu cpf: ");
		minhaConta.cpf = ler.nextInt();
		System.out.printf("Informe o saldo inicial dessa conta: R$ ");
		minhaConta.saldo = ler.nextDouble();

		while(flag){
			System.out.printf("\n\n\tINFORME A OPÇÃO DESEJADA:\n1. Consultar Saldo\n2. Efetuar Saque\n3. Efetuar Deposito\n4. Ver informações da conta\n5. Sair\n");
			do{
				if(ler.hasNextInt()){
				opcao = ler.nextInt();
				flag_menu = true;
				}else{
					flag_menu = false;
					ler.nextLine();
				}
			}while(!flag_menu);
			switch(opcao){
				case 1:
					System.out.printf("Saldo atual: R$ %.2f", minhaConta.saldo);
					break;
				case 2:
					flag_2 = 1;
					while(flag_2 == 1){
						System.out.printf("Informe o valor que deseja sacar: ");
						valor_saque = ler.nextDouble();
						if(minhaConta.sacar(valor_saque)){ // se a "função" minhaConta.sacar retornar verdadeiro
							System.out.printf("\nSaque Efetuado!\nNovo saldo: %.2f\n", minhaConta.saldo);
						}else{
							System.out.printf("\tERROR! Saldo atual: R$ %.2f\n", minhaConta.saldo);
						}
						System.out.print("Repetir Operação?\nSim[1]|| Nao[2]: ");
						continuar_saque = ler.nextInt();
						if(continuar_saque == 2)
							flag_2 = 0;
					}
					break;
				case 3:
					flag_3 = 1;
					while(flag_3 == 1){
						System.out.print("Informe o saldo do depósito: R$ ");
						valor_deposito = ler.nextDouble();
						minhaConta.depositar(valor_deposito);
						System.out.print("Repetir Operação?\nSim[1] || Nao[2]: ");
						continuar_deposito = ler.nextInt();
						if(continuar_deposito == 2)
							flag_3 = 0;
					}
					break;
				case 4:
					System.out.println("\tINFORMAÇÕES DA CONTA");
					System.out.println("Titular: " + minhaConta.dono);
					System.out.println("Número: " + minhaConta.numero);
					System.out.println("CPF: " + minhaConta.cpf);
					System.out.printf("Saldo: R$ %.2f\n", minhaConta.saldo);
					break;
				case 5:
					System.out.println("Saindo...");
					flag = false;
					break;
				default:
					System.out.println("** ERROR! **\nInforme um número entre [1] a [5]!") ;
					break;
			}
		}
	}
}