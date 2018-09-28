/* Implemente o algoritmo insertionSort usando listas;
Use a função rand() da biblioteca stdlib.h para gerar números aleatórios;
Use a função time da biblioteca time.h e calcule o tempo (em segundos) que o algoritmo requer. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50 // elementos a serem inseridos na lista

typedef struct _lista{
	int info;
	struct _lista *prox;
	struct _lista *ant;
}lista;

lista *insere_inicio(lista *l, int n);
lista *insertion_sort( lista *l);
lista *inicia();
void imprime_lista(lista* l);

int main(){
	lista *l = inicia();
	int i;
	time_t t1, t2;
	srand(clock());
	for(i=0; i<=MAX; i++){ // inserindo os valores na lista
		l = insere_inicio(l, rand() % MAX);
	}
	system("clear");
	t1 = clock();
  	insertion_sort(l);
	t2 = clock();
	printf("Ordenada\n");
	imprime_lista(l);	
	printf("A ordenação teve um tempo de: %lf\n",(double)(t2-t1)/CLOCKS_PER_SEC);
  return 0;
}

lista *inicia(){
	return NULL;
}

lista *insere_inicio(lista *l, int n){
	lista *novo = (lista*)malloc(sizeof(lista));
	if(l == NULL){
		novo->info = n;
		novo->prox = NULL;
		novo->ant = NULL;
		return novo;
	}
	novo->info = n;
	novo->prox = l;
	novo->ant = NULL;
	l->ant = novo;
 return novo;
}

lista *insertion_sort( lista *l){
	lista *aux_l = l, *chave = l->prox;
	int aux_numero;
	while(chave != NULL){
		while(aux_l != chave){
			if(chave->info < aux_l->info){
				aux_numero = chave->info;
				chave->info = aux_l->info;
				aux_l->info = aux_numero;
			}
			aux_l = aux_l->prox;
		}
		aux_l = l;
		chave = chave->prox;
	}
	return l;
}

void imprime_lista(lista* l){
	lista *p = l;
	while(p != NULL){
		printf("%d ", p->info);
		p = p->prox;
	}
	printf("\n\n");
}