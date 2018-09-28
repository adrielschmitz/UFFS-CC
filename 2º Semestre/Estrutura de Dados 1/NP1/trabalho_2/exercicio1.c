/*1) Implemente um programa, baseado no programa ex0Malloc.c
para alocar memória para um vetor. O número de posições do vetor
será indicado via teclado. Após a atribuição de valores às posições do
vetor, o programa deve imprimir (na tela) estes valores em ordem
inversa à inserção.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int p, i, j;//cria ponteiro para um inteiro
	printf("Informe o número de posicoes de um vetor: ");
	scanf("%d", &p);
	int *j = (int*) malloc(sizeof(int)*p); //aloca memória
	printf("Informe os %d valores: ", p);
	int vet[p];
	for(i=0; i<p; i++)
		scanf("%d", &vet[i]);	
	
	for(j=i-1; j>=0; j--) // printagem do resultado;
		printf("%d ", vet[j]);
	
	printf("\n");
	free(*j); //libera a memória

	return 0;
}
