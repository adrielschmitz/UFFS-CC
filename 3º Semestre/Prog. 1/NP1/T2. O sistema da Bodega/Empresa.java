import java.util.*;
class Empresa{
	int tamanho = 3;
	//EMPRESA -----------------------------------------------------------------------------------------------------
		String nomeEmpresa, cnpj;

		public Empresa(String nomeEmpresa, String cnpj){
			this.nomeEmpresa = nomeEmpresa;
			this.cnpj = cnpj;
		}
		void imprimirEmpresa(){
			System.out.println("\n\t\tNOME DA EMPRESA: " + nomeEmpresa + "\n\t\tCNPJ: " + cnpj);
		}
	//-------------------------------------------------------------------------------------------------------------
	//FUNCIONÁRIOS ------------------------------------------------------------------------------------------------
		Funcionarios bodegueiros[] = new Funcionarios[tamanho];
		int qtd_func = 0;

		void Contrata(Funcionarios novoEscravo){
			if(qtd_func < tamanho){
				this.bodegueiros[this.qtd_func] = novoEscravo;
				qtd_func++;
			}else{
				System.out.println("\t\t**ERROR***\nNúmero máximo de funcionário atingido!");
			}
		}
		void imprimirFuncionarios(){
			int flag = 0;
	      	System.out.println("\n\t\t        Lista de Funcionarios     ");
			System.out.println("\t\t----------------------------------------");
			while(flag < this.qtd_func){
				System.out.println("\t\t" +(flag+1)+ "º");
				System.out.println("\t\tNOME: " + bodegueiros[flag].nome);
				System.out.println("\t\tCARGO: " + bodegueiros[flag].cargo);
				System.out.printf("\t\tSALARIO: R$ %.2f\n", bodegueiros[flag].salario);
				System.out.println("\t\tCPF: " + bodegueiros[flag].cpf);
				System.out.println("\t\tENDEREÇO " + bodegueiros[flag].endereco);
				System.out.println("\t\tTELEFONE: " + bodegueiros[flag].telefone+ "\n");
				flag++;
			}
			System.out.println("\t\t----------------------------------------");
		}
	//--------------------------------------------------------------------------------------------------------------
	//BEBIDAS ------------------------------------------------------------------------------------------------------
		int contador_bebidas=0;

		Bebida[] bebidas = new Bebida[3];
		void armazenaBebida(Bebida bebida_da_vez){
			if(contador_bebidas < 3){
				this.bebidas[this.contador_bebidas] = bebida_da_vez;
				contador_bebidas++;
			}
		}
		void mostrarBebidas(){
			int flag = 0;
	      	System.out.println("\n\t\t           Lista de Bebidas           ");
			System.out.println("\t\t----------------------------------------");
			while(flag < this.contador_bebidas){
				System.out.println("\t\t ["+(flag+1)+"] " +bebidas[flag].nomeBebida);
				System.out.println("\t\t Teor Alcoólico: " +bebidas[flag].teorAlcoolico);
				System.out.println("\t\t Quantidade: " +bebidas[flag].ml);
				System.out.printf("\t\t Preço: R$ %.2f\n", bebidas[flag].preco);
				System.out.println("\t\t Estoque: " + bebidas[flag].estoque + "\n");
				flag++;
			}
	      	System.out.println("\t\t----------------------------------------");
		}
		boolean confereEstoque(int quantidade, int idBebida){
			return quantidade <= bebidas[idBebida-1].estoque ? true : false;
		}
		void Vender(int quantidade, int idBebida){
			System.out.printf("\t\tFicou R$ %.2f \n", (double)(quantidade*bebidas[idBebida-1].preco));
			bebidas[idBebida-1].estoque -= quantidade;
		}
		void Comprar(int quantidade, int idBebida){
			bebidas[idBebida-1].estoque += quantidade;
		}
	//--------------------------------------------------------------------------------------------------------------
	//CLIENTES -----------------------------------------------------------------------------------------------------
		Clientes[] cliente = new Clientes[tamanho];
		int qts_clientes = 0;

		void adicionaClientes(Clientes novoCliente){
			if(qts_clientes < tamanho){
				this.cliente[qts_clientes] = novoCliente;
				qts_clientes++;
			}else{
				System.out.println("\t\t**ERROR***\nNúmero máximo de funcionário atingido!");
			}
		}
		void mostraClientes(){
			int flag = 0;
			System.out.println("\n\t\t        Lista de Clientes           ");
			System.out.println("\t\t----------------------------------------");
			while(flag < this.qts_clientes){
				System.out.println("\t\t" +(flag+1)+ "º");
				System.out.println("\t\tNOME: " + cliente[flag].nome);
				System.out.println("\t\tCPF: " + cliente[flag].cpf);
				if(cliente[flag].confiavel){
					System.out.println("\t\tCONFIÁVEL: SIM!");
				}else{
					System.out.println("\t\tCONFIÁVEL: NAO!");
				}
			  System.out.printf("\n");
			  flag++;
			}
			System.out.println("\t\t----------------------------------------");
		}
	//--------------------------------------------------------------------------------------------------------------
	void menu(){
		System.out.println("\n\t\t|----------------------------------------|");
    	System.out.println("\t\t|             ßød€ga Dø Cadú             |");
    	System.out.println("\t\t|----------------------------------------|");
		System.out.println("\t\t|[1] Mostrar dados da Empresa            |");
		System.out.println("\t\t|[2] Contratar Funcionarios              |");
		System.out.println("\t\t|[3] Mostrar Dados dos Funcionarios      |");
		System.out.println("\t\t|[4] Vender                              |");
		System.out.println("\t\t|[5] Comprar do Fornecedor               |");
		System.out.println("\t\t|[6] Cadastrar Clientes                  |");
		System.out.println("\t\t|[7] Mostrar Clientes Cadastrados        |");
		System.out.println("\t\t|[8] Sair                                |");
    	System.out.println("\t\t|----------------------------------------|");
		System.out.printf("\t\t Opção → ");
	}
}