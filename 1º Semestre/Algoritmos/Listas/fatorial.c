#include <stdio.h>
int fatorial(int x) { return x==0 ? 1 : x*fatorial(x-1); }

int main(void){
	int entrada;
	scanf ("%d", &entrada);
	fatorial(entrada);
	printf("O fatorial de %d eh = %d\n", entrada, fatorial(entrada));
	return 0;
}