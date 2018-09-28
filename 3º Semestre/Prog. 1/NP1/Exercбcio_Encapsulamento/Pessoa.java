class Pessoa{
	private int idade;
	private float peso;
	private String nome;

	public String getNome(){
		return this.nome;
	}
	public void setNome(String parametro){
		this.nome = parametro;
	}

	public int getIdade(){
		return this.idade;
	}
	public void setIdade(int parametro){
		this.idade = parametro;
	}

	public float getPeso(){
		return this.peso;
	}
	public void setPeso(float parametro){
		this.peso = parametro;
	}
}