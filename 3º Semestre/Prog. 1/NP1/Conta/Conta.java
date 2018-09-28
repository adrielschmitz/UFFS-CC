class Conta{
	int numero, cpf;
	String dono;
	double saldo;

	boolean sacar(double valor){
		if(valor > this.saldo)
			return false;
		else{
			this.saldo -= valor;
			return true;
		}
	}

	void depositar(double valor){
		this.saldo += valor;
		System.out.printf("Depósito realizado com sucesso!\nNovo saldo: R$ " + this.saldo + "\n");
	}
}
