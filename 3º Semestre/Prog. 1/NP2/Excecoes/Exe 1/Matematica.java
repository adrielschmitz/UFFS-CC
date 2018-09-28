import java.util.*;

public class Matematica{
	Scanner ler = new Scanner(System.in);
	double a, b;

	public void testaDados() throws ParamZeroException{
		System.out.printf("Informe os dois valores → ");
		this.a = ler.nextDouble();
		this.b = ler.nextDouble();
		if(a*b == 0)
			throw new ParamZeroException();
	}

	public double somar() throws ResultadoZeroException{
		double resultado = this.a + this.b;
		if(resultado == 0)
			throw new ResultadoZeroException();
		else
			return resultado;
	}
	public double subtrair() throws ResultadoZeroException{ 
		double resultado = this.a - (this.b);
		if(resultado == 0)
			throw new ResultadoZeroException();
		else
			return resultado;
	}
	public double dividir() throws ResultadoZeroException{
		double resultado = this.a / this.b;
		if(resultado == 0) 
			throw new ResultadoZeroException();
		else 
			return resultado;
	}
	public double multiplicar() throws ResultadoZeroException{ 
		double resultado = this.a * this.b;
		if(resultado == 0)
			throw new ResultadoZeroException();
		else return resultado;
	}
}