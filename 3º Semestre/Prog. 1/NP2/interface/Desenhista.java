class Desenhista{
	public void desenhar(Desenhavel d){
		if(d instanceof Quadrado)
			System.out.println("É um Quadrado...");
		if(d instanceof Circulo)
			System.out.println("É um Circulo...");
		if(d instanceof trianguloRetangulo){
			System.out.println("É um Triangulo Retangulo...");
		}else if(d instanceof Triangulo){
			System.out.println("É um Triangulo...");
		}
	}
}
