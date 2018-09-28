import java.util.*;
public class Teste{
	public static void main(String[] args){
		System.out.println("Zoo: ");
		Animal animal = new Animal("Camelo", "Amarelo", "Terra", 150, 2.0, 4);
		animal.dados();
		Peixe animal_p = new Peixe("Tubarão", "Cinzento", "Mar", 300, 1.5, 0, "Barbatanas e Cauda");
		animal_p.dados();
		Mamifero animal_m = new Mamifero("Urso-do-Canadá", "Vermelho", "Terra", 180, 1.5, 4, "Mel");
		animal_m.dados();
	}
}