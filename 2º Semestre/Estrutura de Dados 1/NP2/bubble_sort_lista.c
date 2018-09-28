#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5000 // quantidade de nós a serem inseridos na lista
#define PRINT 0 // caso deseja imprimir a lista mude o PRINT para '1'

typedef struct _lista{
	int info;
	struct _lista *prox;
	struct _lista *ant;
}lista;

lista *inicia();
lista *insere_inicio(lista *l, int n);
void bubble_sort(lista *l);
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
	bubble_sort(l);
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

void bubble_sort(lista *l){
	lista *aux_l;
	int trocou;
	do{
		aux_l = l;
		trocou = 0;
		while(aux_l->prox != NULL){
			if(aux_l->info > aux_l->prox->info){
				//printf("%p\n", aux_l); //teste pra ver o aponteiramento
				int cont = 0;
				cont = aux_l->info;
				aux_l->info = aux_l->prox->info;
				aux_l->prox->info = cont;
				trocou = 1;
			}
			aux_l = aux_l->prox;
		}
	}while(trocou);
}

void imprime(lista *l){
	lista *aux = l;
	while(aux != NULL){
		printf("%d ", aux->info);
		aux = aux->prox;
	}
	printf("\n\n");
}