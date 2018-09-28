#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX 500
#define MAX2 MAX/2

void radix_sort(int vetor[], int n);
void imprime();

int main(void){
	int vetor[MAX],i;
	time_t t1, t2;
	srand(clock());

	system("clear");

	for(i=0; i<MAX; i++){ vetor[i] = rand() % MAX; }
	printf("Vetor antes do Radix Sort\n");
	imprime(vetor);
	t1 = clock();
	radix_sort(vetor, MAX); // chama a função radix_sort para ordenar o vetor
 	t2 = clock();
	printf("\nVetor depois do Radix Sort: ");
	imprime(vetor);
	printf("A ordenação teve um tempo de: %lf\n",(double)(t2-t1)/CLOCKS_PER_SEC);

  return 0;
}
 
void radix_sort(int vetor[], int n){
	int bucket[MAX], buck[MAX];
	int i, j, k, l, num, divide, large, passes;
  
	divide=1;
	num=0;
	large=vetor[0];
 
 	for(i=0 ; i < n ; i++){
		if(vetor[i] > large){
			large = vetor[i];
		}
		while(large > 0){
			num++;
			large = large/10;
		}
 
		for(passes=0 ; passes < num ; passes++){
 			for(k=0 ; k < 10 ; k++){
				buck[k] = 0;
			}

			for(i=0 ; i < n  ;i++){
				l = ((vetor[i]/divide)%10);
				bucket[l++] = vetor[i];
			}

 		  i=0;

			for(k=0 ; k< 10 ; k++){
				for(j=0 ; j < buck[k] ; j++){
					vetor[i++] = bucket[k];
				}
			}
 
			divide*=10;
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