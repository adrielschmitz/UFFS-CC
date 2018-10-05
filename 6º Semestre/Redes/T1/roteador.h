#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <pthread.h>
#include "config.h"
#include "priority_queue.h"         // fila de prioridade para o dijsktra

typedef struct{                     // estrutura da tabela de roteamento
    int first;                      // second = distancia total para aquele roteador
    int second;                     // first = próximo salto
}pair;

pair grafoListaAdj[N_ROUT][N_ROUT], leTemp; // estrutura para o dijkstra

struct sockaddr_in si_me;         	// Socket para recebimento e envio de pacotes

pthread_t receber_id;               // Declara uma thread para recebimento da mensagem

typedef struct{		                // estrutura para as variáveis usadas pra controlar a mensagem 
    int id;			                // id do roteador que será instanciado
    int sock;		                // armazena o socket de envio da mensagem
    int nova;		                // quantidade de mensagens novas
    int qtd_msg;	                // auxiliar para contar a quantidade de mensagens recebidas
    int slen;		                // para verificar o tamanho da mensagem
}tipo;

typedef struct{                     // estrutura para o roteador
  	int id;                         // id do roteador instanciado 
    int porta;                      // porta referente a este roteador
  	char ip[30];                    // IP do roteador
}router_t;

typedef struct{                     // estrutura do pacote que será enviado
  	int origem;                     // armazena o ID do roteador de origem
    int destino;                    // tem o ID do roteador de destino
    int numero;                     // identificador do pacote. Ex: Pacote [3]...
  	char mensagem[MENSAGEM_SIZE];   // a mensagem que será enviada
}pacote_t;

// DECLARACOES DE FUNCOES USADAS -------------------------------------------------------------------
void configura_roteador(int id, int *sock, struct sockaddr_in *si_me, router_t roteadores[]);
void enviar_pacote(pacote_t aux_pacote, int sock, int slen, int flag);
void print_tabela_roteamento(pair tabela_roteamento[], int id);
void dijkstra(int id, pair tabela_roteamento[], int grau[]);
void print_caixa_entrada(tipo info_msg, pacote_t pacote[]);
void configura_enlace(int id, pair tabela_roteamento[]);
int backtracking(int inicial, int atual, int caminho[]);
void menu(int id, int novas, char LOG[]);
void print_barra_caixa_saida();
void *receber(void *nothing);
int toint(char *str);
void die(char* msg);
