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

typedef struct _asciiart{
	int indice;
	char desenho[5][22];
	struct _asciiart *prox;
}Asciiart;

//FUNÇÕES-----------------------------------------------------------------------------------------------------
TppecaDomino *insere_mesa(TppecaDomino *mesa, TppecaDomino *jogada, int lado);
TppecaDomino *remove_peca_jogada(TppecaDomino *mao, TppecaDomino *jogada);
TppecaDomino *insere_inicio(TppecaDomino *l, int num1, int num2);
TppecaDomino *excluir(TppecaDomino *l, int num1, int num2);
TppecaDomino *insere_fim(TppecaDomino *l, int m, int n);
TppecaDomino *copiar(TppecaDomino *l, int num);
TppecaDomino *inicializa();
TppecaDomino *cria_pecas();
//------------------------------------------------------------------------------------------------------------
Asciiart *chama_desenho(TppecaDomino *l);
Asciiart *aloca_desenho(Asciiart *peca);
Asciiart *inicializa_ascii_art();
//------------------------------------------------------------------------------------------------------------
int valida_jogada(TppecaDomino *mesa, TppecaDomino *jogada);
int testa_pecas(TppecaDomino *l, TppecaDomino *mesa);
int contar_elementos(TppecaDomino *l);
int contar_elementosasc(Asciiart *l);
//-----------------------------------------------------------------------------------------------------------
void imprime_info(TppecaDomino *mesa, TppecaDomino *mao_jogador, TppecaDomino *mao_bot, TppecaDomino *monte);
void quem_ganhou(TppecaDomino *jogador, TppecaDomino *bot, TppecaDomino *monte);
void desenhar(Asciiart *peca, int valor, int x, int fazer);
void printar_ascii_art_jogador(Asciiart *peca);
void printar_ascii_art_mesa(Asciiart *peca);
void imprime(TppecaDomino *l);
void creditos();

#include "funcoes.c"
#endif