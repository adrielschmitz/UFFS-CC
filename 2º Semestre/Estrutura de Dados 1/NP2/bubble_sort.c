#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20

void bubble_sorte(int a[]);
void imprime(int vet[]);

int main(){
	int vet[MAX], i;
	time_t t1, t2;
	srand(clock());
	for(i=0; i<MAX; i++){
		vet[i] = rand() % MAX;		
	}
	system("clear");
	printf("Antes\n");
	imprime(vet);
	t1 = clock();
	bubble_sorte(vet);
	t2 = clock();
	printf("Ordenado\n");
	imprime(vet);
	printf("A ordenação teve um tempo de: %lf\n",(double)(t2-t1)/CLOCKS_PER_SEC);

	return 0;
}

void bubble_sorte(int a[]){
	int i, trocou;
	do{
		trocou = 0;
		for(i=1; i<=MAX; i++){
			if(a[i-1] > a[i]){
				int aux=0;
				aux = a[i-1];
				a[i-1] = a[i];
				a[i] = aux;
				trocou = 1;
			}
		}
	}while(trocou);
}

void imprime(int vet[]){
	int i;
	for(i=0; i<MAX; i++){
		printf("%d ", vet[i]);
	}
	printf("\n\n");
}
