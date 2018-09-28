/* 	UNIVERSIDADE FEDERAL DA PRONTEIRA SUL - UFFS
	3º FASE DO CURSO DE CIÊNCIA DA COMPUTAÇÃO
	Trabalho I da desciplina de ESTRUTURA DE DADOS II - 2017
	Implementação da Arvore AVL com valores positivos em C Ansi
	Alunos: ADRIEL SCHMITZ e MAICON BRANDÃO
	Professor: Doglas André Finco
*/
#ifndef FUNCOES_AVL
#define FUNCOES_AVL

typedef struct _nodo{
	int chave;
	int altura, nivel;
	int altdireita, altesquerda;
	struct _nodo *esq;
	struct _nodo *dir;
	struct _nodo *pai;
}TpNodo;

typedef struct _arvore{
	TpNodo *raiz;
}TpArvore;

TpNodo *Rotacao_joelho_direita_esquerda(TpNodo *avo);
TpNodo *Rotacao_joelho_esquerda_direita(TpNodo *avo);
TpNodo *Rotacao_Simples_Esquerda(TpNodo *nodo);
TpNodo *inserir_nodo(TpNodo *arvore, int numero);
TpNodo *Rotacao_Simples_Direita(TpNodo *nodo);
TpNodo *Balanceamento(TpNodo *arvore);
TpNodo *Nodo_com_problema(TpNodo *arvore);
TpArvore *inicializa();
int Busca_altura(TpNodo *arvore);
void Busca_nivel(TpNodo *arvore, int x);
void Imprime_arvore(TpNodo *arvore);
void menu();

#include "funcoes_avl.c"
#endif