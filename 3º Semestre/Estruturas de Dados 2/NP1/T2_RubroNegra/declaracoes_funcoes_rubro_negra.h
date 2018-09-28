/* 	UNIVERSIDADE FEDERAL DA PRONTEIRA SUL - UFFS
	3º FASE DO CURSO DE CIÊNCIA DA COMPUTAÇÃO
	Trabalho II da desciplina de ESTRUTURA DE DADOS II - 2017
	Implementação da Arvore RUBRO NEGRA com valores positivos em C Ansi
	Alunos: ADRIEL SCHMITZ e MAICON BRANDÃO
	Professor: Doglas André Finco
*/
#ifndef FUNCOES_RUBRO_NEGRA
#define FUNCOES_RUBRO_NEGRA

#define BLACK 0
#define RED 1

typedef struct _nodo{
	int chave;
	int cor;
	struct _nodo *esq;
	struct _nodo *dir;
	struct _nodo *pai;
} TpNodo;

typedef struct _arvore{
	TpNodo *raiz;
	TpNodo *sentinela;
} TpArvore;

TpNodo *insere_nodo(TpNodo *arvore, int numero);
TpNodo *verifica_propriedades(TpNodo *filho);
TpNodo *retorna_raiz(TpNodo *raiz);
TpNodo *busca_avo(TpNodo *nodo);
TpNodo *busca_tio(TpNodo *nodo);
TpNodo *caso_1(TpNodo *nodo);
TpNodo *caso_2(TpNodo *nodo);
TpNodo *caso_3(TpNodo *nodo);
void imprime_arvore(TpNodo *arvore);
void inverte_cor(TpNodo *nodo);
void menu();
int busca_cor(TpNodo *nodo);

#include "funcoes_rubro_negra.c"
#endif