#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define T 2

typedef struct Nodo{
	int chave;
	struct Nodo *prox;
	struct Pagina *fesq;
	struct Pagina *fdir;
}TpNodo;

typedef struct Pagina{
	int chaves;
	struct Pagina* pai;
	bool folha;
	TpNodo *raiz;
}TpPagina;

TpPagina *split(TpPagina* original,TpPagina *raiz, int t);
TpPagina *inserir(TpPagina *raiz, int n, int t);
void imprime(TpPagina *raiz);
TpPagina *inicializa();
void menu();

int main(){
	TpPagina *raiz = inicializa();
	int op, t, n;
	printf("Digite o valor de t: ");
	while( scanf("%d", &t) != 1 )
		getchar();
	if(t<2) t = 2;
	do{
		menu();
		scanf("%d", &op);
		switch(op){
			case 0:
				break;
			case 1:
				printf("Digite o valor que deseja inserir: ");
				scanf("%d", &n);
				raiz = inserir(raiz, n, t);
				break;
			case 2:
				imprime(raiz);
				break;
			default:
				printf("Opção invalida.\n");
				break;
		}
	}while(op);

	return 0;
}

TpPagina *inicializa(){
	TpPagina *pagina = (TpPagina*)malloc(sizeof(TpPagina));
	pagina->chaves = 0;
	pagina->folha = false;
	pagina->raiz = NULL;
	return pagina;
}

TpPagina *split(TpPagina* original,TpPagina *raiz, int t){
	if(raiz->chaves>((2*t)-1)){
		TpNodo* aux = raiz->raiz, *nodo;
		for(int i = 0; i<(t-1);i++){
			nodo = aux;
			aux = aux->prox;
		}
		TpPagina *novo = inicializa();
		novo->folha = raiz->folha;
		aux->fesq = raiz;
		aux->fdir = novo;
		novo->pai = raiz->pai;
		raiz->chaves = t-1;
		novo->chaves = t;
		if(raiz->pai == NULL){
			TpPagina *promote = inicializa();
			promote->chaves++;
			promote->raiz = aux;
			novo->raiz = aux->prox;
			raiz->pai = promote;
			novo->pai = promote;
			aux->prox = NULL;
			nodo->prox = NULL;
			return promote;
		}
		novo->raiz = aux->prox;
		aux->prox = NULL;
		nodo->prox = NULL;
		TpNodo* pai = raiz->pai->raiz;
		TpNodo* auxP = NULL;
		if(pai != NULL){
			while(pai->fesq != raiz){
				auxP = pai;
				pai = pai->prox;
				if(pai == NULL){
					break;
				}
	
			}
		}
		if(auxP != NULL){
			auxP->fdir = raiz;
			auxP->prox = aux;
		}
		if(pai != NULL){
			pai->fesq = novo;
		}
		aux->prox = pai;
		if(auxP == NULL){
			raiz->pai->raiz = aux;
		}
		raiz = raiz->pai;
		raiz->chaves++;
		original = split(original, raiz, t);
	}
	return original;
}

TpPagina *inserir(TpPagina *raiz, int n, int t){
	TpNodo *novo, *nodo, *nodoAterior;
	TpPagina *pNodo;
	novo = (TpNodo*)malloc(sizeof(TpNodo));
	novo->chave = n;
	novo->prox = NULL;
	novo->fesq = NULL;
	novo->fdir = NULL;
	
	if(raiz->raiz == NULL){ 		// Se for o 1º elemento da arvore
		raiz->chaves ++;
		raiz->folha = true;
		raiz->raiz = novo;
		raiz->pai = NULL;
		return raiz;
	}

	pNodo = raiz;
	while(pNodo->folha != true){	//Busca a pagina onde deve ser inserido
		nodoAterior = NULL;
		nodo = pNodo->raiz;
		while(n > nodo->chave){
			nodoAterior = nodo;
			nodo = nodo->prox;
			if(nodo == NULL){
				break;
			}
		}
		if(nodoAterior == NULL){
			pNodo = nodo->fesq;
		}else{
			pNodo	 = nodoAterior->fdir;
		}
	}

	nodo = pNodo->raiz;			//pNodo é a pagina onde sera inserido
	nodoAterior = NULL;

	while(n > nodo->chave){		//Encontra onde deve ser inserido na pagina
		nodoAterior = nodo;
		nodo = nodo->prox;
		if(nodo == NULL){
			break;
		}
	}

	pNodo->chaves++;
	novo->prox = nodo;

	if(nodoAterior == NULL){		//Se for o 1º elemento da pagina
		pNodo->raiz = novo;
	}else{					//Senão o elemento é inserido no meio da pagina
		nodoAterior->prox = novo;
	}
	//Se preencheu a pagina faz split
	raiz = split(raiz, pNodo, t);

	return raiz;
}

void imprime(TpPagina *raiz){
	TpNodo *nodo;
	if(raiz != NULL){
		nodo = raiz->raiz;
		while(nodo != NULL){
			printf("Chave: %d  ", nodo->chave);
			imprime(nodo->fesq);
			if(nodo->prox	 == NULL){
				imprime(nodo->fdir);
			}
			nodo = nodo->prox;
		}
	}
}

void menu(){
	printf("[0] Sair.\n");
	printf("[1] Inserir elemento.\n");
	printf("[2] Mostrar elemntos.\n");
	printf("→ ");
}
