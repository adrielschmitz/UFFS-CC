/* ex0Malloc.c */
#include <stdio.h>
#include <stdlib.h>

int main(){
	int *p; //cria ponteiro para um inteiro
	p = (int *)malloc(sizeof(int)); //aloca memória
	if(p){ //testa se memória foi alocada
		printf("Memória alocada com sucesso.\n");
	}else{
		printf("Não foi possivel alocar a memória.\n");
		return 0; //finaliza o programa
	}
	*p = 10; //atribui valor na memória alocada
	printf("Valor: %d\n\n", *p); //imprime o valor
	free(p); //libera a memória

	return 0;
}