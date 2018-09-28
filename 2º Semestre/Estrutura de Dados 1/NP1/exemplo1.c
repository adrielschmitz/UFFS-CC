#include <stdio.h>
#include <stdlib.h>

void quadrado(int *a, int *b){
	*a= (*a)*(*a);
	*b= (*b)*(*b);
}

int main(){
	calloc (4, sizeof(int));
	int a, b;
	printf("Informe dois valores\n");
	scanf("%d %d", &a, &b);
	quadrado(&a, &b);
	printf("O quadrado de a eh: %d, e o quadrado de b eh: %d\n", a, b);
}
