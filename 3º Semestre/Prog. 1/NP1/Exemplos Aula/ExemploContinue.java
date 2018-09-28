// Exemplo do comando continue
public class ExemploContinue{
	public static void main(String[] args){
		int i;
		for(i=0; i<=30; i++){
			if((i>10) && (i<20))
				continue;
		}
		System.out.println("i = " + i);
	}
}

// saída: i = 31