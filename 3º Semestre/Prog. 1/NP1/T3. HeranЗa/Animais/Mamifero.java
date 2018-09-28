public class Mamifero extends Animal{
	private String alimento;
	//construtor publico
	public Mamifero(String nome, String cor, String ambiente, int comprimento, double velocidade, int patas, String alimento){
		super(nome, cor, ambiente, comprimento, velocidade, patas);
		this.alimento = alimento;
	}
	//geter e seters
	public String getAlimento(){
		return this.alimento;
	}
	public void setAlimento(String alimento){
		this.alimento = alimento;
	}
	//-------------------------------------------
	@Override
	public void dados(){
		super.dados();
		System.out.println("ALIMENTO: " + getAlimento() +
						   "\n-----------------------------" );
	}
}	