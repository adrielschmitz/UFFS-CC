#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct _l{
	int grau;
	int vertice;
	int cor;
	struct _l *prox;
}lista;

void insere_lista(lista **l, int g, int v, int c){
	lista *novo = (lista *)malloc(sizeof(lista));
	
	novo->vertice = v;
	novo->grau = g;
	novo->cor = c;
	novo->prox = NULL;
	if(*l == NULL){
		*l = novo;
		return;
	}
	lista *aux = *l;
	while(aux->prox != NULL){
		aux = aux->prox;
	}
	aux->prox = novo;
}

void imprime_lista(lista *l){
	if(l != NULL){
		printf("%d %d %d\n", l->grau, l->vertice, l->cor);
		imprime_lista(l->prox);
	}
}
int main(int argc, char const *argv[]){
	lista *l = NULL;
	insere_lista(&l, 1, 1, 1);
	insere_lista(&l, 2, 5, 2);
	insere_lista(&l, 3, 10, 1);
	insere_lista(&l, 4, 5, 2);
	insere_lista(&l, 5, 7, 1);
	insere_lista(&l, 6, 5, 2);
	insere_lista(&l, 7, 3, 1);
	imprime_lista(l);
	return 0;
}