public class Publicacao{ //super classe
	private String nome;
	private double precoExemplar;
	protected double valorAnuidade;
	Editora editora;
	//construtor publico
	public Publicacao(String nome, double precoExemplar){
		this.nome = nome;
		this.precoExemplar = precoExemplar;
		calcularAnuidade();
	}
	//geters
	public String getNome(){
		return this.nome;
	}
	public double getPrecoExemplar(){
		return this.precoExemplar;
	}
	public double getValorAnuidade(){
		return this.valorAnuidade;
	}
	//seters
	public void setNome(String n){
		this.nome = n;
	}
	public void setPrecoExemplar(double p){
		this.precoExemplar = p;
	}
	public void setValorAnuidade(double v){
		this.valorAnuidade = v;
	}
	//métodos públicos
	public void calcularAnuidade(){
		setValorAnuidade(12*getPrecoExemplar());
	}
	public void imprimirDados(){
		System.out.printf("\nNome da Editora: " +editora.getNome()+
						  "\nCNPJ da Editora: " + editora.getCnpj()+
						  "\nNome da Publicação: " +getNome()+
						  "\nPreço do Exemplar: R$ " +getPrecoExemplar()+
						  "\nValor da Anuidade: R$ " +getValorAnuidade() + "\n");
	}

}