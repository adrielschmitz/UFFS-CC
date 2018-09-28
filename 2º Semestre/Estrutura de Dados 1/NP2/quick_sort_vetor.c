#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20

void quick_sort_vetor(int vetor[], int esquerda, int direita){
	int i, j, x, y;

	i = esquerda;
	j = direita;
	x = (int)vetor[(esquerda+direita)/2];

	while(i <= j){
		while((vetor[i],x) < 0 && i < direita){
	    	i++;
	    }

		while((vetor[j],x) > 0 && j > esquerda){
	    	j--;
	    }
	    if(i <= j){
	    	y = vetor[i];
	    	vetor[i] = vetor[j];
	    	vetor[j] = y;
	    	i++;
	    	j--;
	    }
  	}
  	if(j > esquerda){
    	quick_sort_vetor(vetor, esquerda, j);
    }
  	if(i < direita){
    	quick_sort_vetor(vetor, i , direita);
   	}
}

void imprime(int vet[]){
	int i;
	for(i=0; i<MAX; i++){
		printf("%d ", vet[i]);
	}
	printf("\n\n");
}

int main(){
	TpContato v[MAX];
	int i;
	time_t t1, t2;
	srand(clock());
	for(i=0; i<MAX; i++){
		v[i] = rand() % MAX;
	}
	system("clear");
	printf("Antes\n");
	imprime(v);
	t1 = clock();
	quick_sort_vetor(v, v[0], v[MAX-1]);
	t2 = clock();
	printf("Ordenado\n");
	imprime(v);
	printf("A ordenação teve um tempo de: %lf\n",(double)(t2-t1)/CLOCKS_PER_SEC);

  return 0;
}
