public abstract class formaGeo implements Rotacionavel, Desenhavel{
	public abstract void area();
	//métodos das interfaces
	public void rotacionar(){
		System.out.println("Rotacionando...");
	}
	public void desenhar(){
			System.out.println("Desenhando... ");
	}
}