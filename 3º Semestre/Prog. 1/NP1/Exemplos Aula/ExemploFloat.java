import java.text.DecimalFormat;
public class ExemploFloat{
	public static void main(String[] args){
		DecimalFormat f = new DecimalFormat("0.00");
		int a = 15, b = 10;
		System.out.println("Valor: " + f.format(((float) a/b)));
	}
}