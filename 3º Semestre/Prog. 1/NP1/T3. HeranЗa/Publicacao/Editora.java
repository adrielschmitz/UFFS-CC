public class Editora{
	private String nome;
	private String cnpj;

	public Editora(String nome, String cnpj){
		this.nome = nome;
		this.cnpj = cnpj;
	}
	//geters
	public String getNome(){
		return this.nome;
	}
	public String getCnpj(){
		return this.cnpj;
	}
	//seters
	public void setNome(String nome){
		this.nome = nome;
	}
	public void setCnpj(String cnpj){
		this.cnpj = cnpj;
	}
}