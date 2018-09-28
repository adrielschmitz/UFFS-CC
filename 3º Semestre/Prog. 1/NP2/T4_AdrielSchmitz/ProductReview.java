/*  TRABALHO 04 da NP2
	Aluno: ADRIEL SCHMITZ
	Disciplina: PROGRAMAÇÃO 1
	Professor: DOGLAS ANDRÉ FINCO
*/
public class ProductReview extends Post implements Evaluable{
	private String brand;
	private int stars;
	//geters
	public String getBrand(){
		return this.brand;
	}
	public int getStars(){
		return this.stars;
	}
	//seters
	public void setBrand(String b){
		this.brand = b;
	}
	public void setStars(int s){
		this.stars = s;
	}
	//método interface Evaluable
	public void evaluate(int value){
		if(value >= 1 && value <= 10){
			this.stars = value;
		}else{
			System.out.println("VALOR INVALIDO. INFORME ENTRE 1 A 10!");
		}
	}
	//método publico da classe
	@Override
	public void show(){
		super.show();
		System.out.println( "Marca: " +this.brand+
							"\nEstrelas: " + this.stars );
	}
}