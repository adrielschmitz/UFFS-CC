class Bhaskara{
	int a, b, c;

	public Bhaskara(int a, int b, int c){
		this.a = a;
		this.b = b;
		this.c = c;
	}

	void imprime_raiz(){
		double raiz = Math.sqrt((b*b)-(4*a*c));
		double x1, x2;
		x1 = ((-b) + raiz) / 2*a;
		x2 = ((-b) - raiz) / 2*a;
		System.out.println("X¹ = " + x1);
		System.out.println("X² = " + x2);
	}
}