import java.util.*;

public class Teste{
	public static void main(String[] args){
		
		Desenhavel c = new Circulo();
		Desenhavel q = new Quadrado();
		Desenhavel t = new Triangulo();
		Desenhavel tr = new trianguloRetangulo();
		Desenhista des = new Desenhista();

		des.desenhar(tr);
		des.desenhar(c);
		des.desenhar(q);
		des.desenhar(t);
	}
}