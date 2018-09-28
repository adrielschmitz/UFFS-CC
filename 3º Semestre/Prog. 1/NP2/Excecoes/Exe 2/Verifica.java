public class Verifica{
	public static int somaInteiros(int[] vet, int tam, int a, int b) throws Exception{
		int resultado = 0, zero = 0;

		for(int i=0; i<tam; i++)
			zero += vet[i];

		if(a > tam || b > tam)
			throw new IntervaloException();
		
		if(zero == 0)
			throw new VetorVazioException();
		
		while(a<=b){
			resultado += vet[a];
			a++;			
		}

		return resultado;
	}
}