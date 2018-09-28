public class Matematica{
	public int verifica(int n)throws NegativeArraySizeException{
		if(n < 0) throw new NegativeArraySizeException();
		
		return n;
	}
}