/* Implemente o algoritmo insertionSort usando vetores;
Use a função rand() da biblioteca stdlib.h para gerar números aleatórios;
Use a função time da biblioteca time.h e calcule o tempo (em segundos) que o algoritmo requer. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50

void insertion_sort( int a[], int n );
void imprime(int vet[]);

int main(){
	int vet[MAX], i;
	time_t t1, t2;
	srand(clock());
	for(i=0; i<=MAX; i++){
		vet[i] = rand() % MAX;		
	}
	system("clear");
	printf("Antes\n");
	imprime(vet);
	t1 = clock();
	insertion_sort(vet, MAX);
	t2 = clock();
	printf("Ordenado\n");
	imprime(vet);
	printf("A ordenação teve um tempo de: %lf\n",(double)(t2-t1)/CLOCKS_PER_SEC);

	return 0;
}

void insertion_sort( int a[], int n ){
	int chave, i, j;
	for(j=1; j<n; j++){
		chave = a[j];
		i = j - 1;
		while(i>= 0 && a[i] > chave){
			a[i+1] = a[i];
			i = i-1;
		}
		a[i+1] = chave;
	}
}

void imprime(int vet[]){
	int i;
	for(i=0; i<MAX; i++){
		printf("%d ", vet[i]);
	}
	printf("\n\n");
}
