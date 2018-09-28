class Animal{ //super Classe
	//atributos privados
	private String nome;
	private int comprimento;
	private int patas;
	private String cor;
	private String ambiente;
	private double velocidade;
	//construtor publico
	public Animal(String nome, String cor, String ambiente, int comprimento, double velocidade, int patas){
		this.nome = nome;
		this.cor = cor;
		this.ambiente = ambiente;
		this.comprimento = comprimento;
		this.velocidade = velocidade;
		this.patas = patas;
	}
	// gerters
	public String getNome(){ 
		return this.nome;
	}
	public int getComprimento(){
		return this.comprimento;
	}
	public int getPatas(){
		return this.patas;
	}
	public String getCor(){
		return this.cor;
	}
	public String getAmbiente(){
		return this.ambiente;
	}
	public double getVelocidade(){
		return this.velocidade;
	}
	// seters
	public void setNome(String nome){
		this.nome = nome;
	}
	public void setComprimento(int comprimento){
		this.comprimento = comprimento;
	}
	public void setPatas(int patas){
		this.patas = patas;
	}
	public void setCor(String cor){
		this.cor = cor;
	}
	public void setAmbiente(String ambiente){
		this.ambiente = ambiente;
	}
	public void setVelocidade(double velocidade){
		this.velocidade = velocidade;
	}
	public void dados(){
		System.out.println( "-----------------------------" + 
							"\nANIMAL: " + getNome() +
						 	"\nCOMPRIMENTO: " + getComprimento() + 
						 	"\nPATAS: " + getPatas() +
						 	"\nCOR: " + getCor() +
						 	"\nAMBIENTE: " + getAmbiente() +
					 	 	"\nVELOCIDADE: " + getVelocidade() + " m/s");
	}

}