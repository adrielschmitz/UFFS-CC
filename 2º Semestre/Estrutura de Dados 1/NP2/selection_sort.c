#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void selection_sort(int v[]);
void imprime(int vet[]);

int main(){
	int v[MAX], i;
	time_t t1, t2;
	srand(clock());
	for(i=0; i<MAX; i++){ v[i] = rand() % MAX; }
	system("clear");
	printf("Antes\n");
	imprime(v);
	t1 = clock();
	selection_sort(v);
	t2 = clock();
	printf("Ordenado\n");
	imprime(v);
	printf("A ordenação teve um tempo de: %lf\n",(double)(t2-t1)/CLOCKS_PER_SEC);

  return 0;
}

void selection_sort(int v[]){
	int i, j, menor;
	for(i=0; i<=MAX-1; i++){
		menor = i;
		for(j=i+1; j<MAX; j++){
			if(v[j] < v[menor]){
				menor = j;
			}
		}
		if(i != menor){
			int aux;
			aux = v[i];
			v[i] = v[menor];
			v[menor] = aux;
		}
	}
}

void imprime(int vet[]){
	int i;
	for(i=0; i<MAX; i++){
		printf("%d ", vet[i]);
	}
	printf("\n\n");
}
