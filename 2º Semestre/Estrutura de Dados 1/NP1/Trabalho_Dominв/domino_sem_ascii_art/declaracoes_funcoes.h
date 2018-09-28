/*	UNIVERSIDADE FEDERAL DA PRONTEIRA SUL - UFFS
	ADRIEL SCHMITZ e MAICON BRANDÃO
	TRABALHO NP1 - ESTRUTURA DE DADOS - 2016/02
	CIÊNCIA DA COMPUTAÇÃO
*/
#ifndef FUNCOES_DOMINO
#define FUNCOES_DOMINO

typedef struct _pecaDomino{
	int numberRight;
	int numberLeft;
	struct _pecaDomino *right;
	struct _pecaDomino *left;
}TppecaDomino;

TppecaDomino *insere_mesa(TppecaDomino *mesa, TppecaDomino *jogada, int lado);
TppecaDomino *remove_peca_jogada(TppecaDomino *mao, TppecaDomino *jogada);
TppecaDomino *insere_inicio(TppecaDomino *l, int num1, int num2);
TppecaDomino *excluir(TppecaDomino *l, int num1, int num2);
TppecaDomino *insere_fim(TppecaDomino *l, int m, int n);
TppecaDomino *copiar(TppecaDomino *l, int num);
TppecaDomino *inicializa();
TppecaDomino *cria_pecas();
//------------------------------------------------------------------------------------------------------------
int valida_jogada(TppecaDomino *mesa, TppecaDomino *jogada);
int testa_pecas(TppecaDomino *l, TppecaDomino *mesa);
int contar_elementos(TppecaDomino *l);
//-----------------------------------------------------------------------------------------------------------
void creditos();
void imprime(TppecaDomino *l);
void imprime_info(TppecaDomino *mesa, TppecaDomino *mao_jogador, TppecaDomino *mao_bot, TppecaDomino *monte);
void quem_ganhou(TppecaDomino *jogador, TppecaDomino *bot, TppecaDomino *monte);

#include "funcoes.c"
#endif