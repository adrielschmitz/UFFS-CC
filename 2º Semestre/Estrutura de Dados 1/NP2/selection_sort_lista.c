#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10 // quantidade de nós a serem inseridos na lista
#define PRINT 1 // caso deseja imprimir a lista mude o PRINT para '1'

typedef struct _lista{
	int info;
	struct _lista *prox;
	struct _lista *ant;
}lista;

lista *inicia();
lista *insere_inicio(lista *l, int n);
void selection_sort(lista *l);
void imprime(lista *l);

int main(){
	lista *l;
	int i;
	time_t ti, tf;
	srand(clock());
	l = inicia();
	for(i=0; i<MAX; i++){
		l = insere_inicio(l, rand() % MAX);
	}
	system("clear");
	if(PRINT == 1){
		printf("Antes.\n");
		imprime(l);
	}
	ti = clock();
	selection_sort(l);
	tf = clock();
	if(PRINT == 1){
		printf("Ordenado.\n");
		imprime(l);
	}
	printf("A ordenação demorou um tempo de: %lf\n", (double)(tf-ti)/CLOCKS_PER_SEC);

  return 0;
}

lista *inicia(){
	return NULL;
}

lista *insere_inicio(lista *l, int n){
	lista *novo = (lista*)malloc(sizeof(lista));
	if(l == NULL){
		novo->info = n;
		novo->ant = NULL;
		novo->prox = l;
		return novo;
	}
	novo->info = n;
	novo->ant = NULL;
	novo->prox = l;
	l->ant = novo;

  return novo;
}

void selection_sort(lista *l){
	lista *aux = l, *j, *menor;

	while(aux->prox != NULL){
	  j = aux->prox;
	  menor->info = aux->info;
		while(j != NULL){
			printf("[1]%p\n", aux->info);
			if(aux->info < menor->info){
				menor->info = j->info;
				printf("[2]%p\n", aux->info);
			}
			j = j->prox;
		}
		if(menor->info != aux->info){
			int cont;
			cont = aux->info;
			aux->info = menor->info;
			menor->info = cont;
		}
	  menor = menor->prox;
	  aux = aux->prox;
	}
}

void imprime(lista *l){
	lista *aux = l;
	while(aux != NULL){
		printf("%d ", aux->info);
		aux = aux->prox;
	}
	printf("\n\n");
}
