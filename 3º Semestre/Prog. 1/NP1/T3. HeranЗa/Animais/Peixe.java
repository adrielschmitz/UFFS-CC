public class Peixe extends Animal{
	private String cascteristicas;

	public Peixe(String nome, String cor, String ambiente, int comprimento, double velocidade, int patas, String cascteristicas){
		super(nome, cor, ambiente, comprimento, velocidade, patas);
		this.cascteristicas = cascteristicas;
	}
	//geters
	public String getCascteristicas(){
		return this.cascteristicas = cascteristicas;
	}
	//seters
	public void setCascteristicas(String cascteristicas){
		this.cascteristicas = cascteristicas;
	}
	@Override
	public void dados(){
		super.dados();
		System.out.println("CARACTERISTICAS: " + getCascteristicas() +
						   "\n-----------------------------" );
	}

}