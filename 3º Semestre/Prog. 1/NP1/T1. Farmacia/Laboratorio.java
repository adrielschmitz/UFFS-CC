class Laboratorio{
	String nome, cnpj, endereco, telefone;

	public Laboratorio(String nome, String cnpj, String endereco, String telefone){
		this.nome = nome;
		this.cnpj = cnpj;
		this.endereco = endereco;
		this.telefone = telefone;
	}

	void PrintarLab(){
		System.out.println("Laboratório: " + nome);
		System.out.println("CNPJ: " + cnpj);
		System.out.println("Endereco: " + endereco);
		System.out.println("Telefone: " + telefone);
	}
}