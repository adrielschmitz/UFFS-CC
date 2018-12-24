#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

#define TEMPO_ATUALIZACAO 2					        //Tempo entre os envios periodicos de vetor de distancia aos vizinhos
#define TOLERANCIA 2 * TEMPO_ATUALIZACAO 	  		//Tempo até o roteador assumir que o vizinho caiu
#define MAX_QUEUE 112345 		              		//Tamanho máximo da fila =~ 1123456
#define TAM_MENSAGEM 200 				            //Tamanho maximo da mensagem
#define MAX_ADRESS 50 					            //Tamanho máximo de um fimereço
#define NROUT 4						                //Numero de Roteadores
#define INF 112345678 	                    		//Infinito =~ 10^8

//Threads usadas
pthread_t enviar_id;
pthread_t receber_id;
pthread_t desempacotar_id;
pthread_t verificar_enlace_id;
pthread_t atualizar_id;

//Mutex usados
pthread_mutex_t log_mutex;
pthread_mutex_t messages_mutex;
pthread_mutex_t estado_mutex;

//Arquivos para logs
FILE *logs, *messages;

//Estrutura com as informações do roteador
typedef struct{
    int id;										//Id do roteador instanciado							
    int porta; 									//Porta do roteador
    int sock;									// Sock usado
    int n_vizinhos;								//Quantidade de vizinhos que esse vértice possui
    char ip[MAX_ADRESS];						//Endereço de IP
}Roteador_t;

//Estrutura de vizinhos
typedef struct{
    int id;										//Seu id
    int custo_original;							//Custo original quando é lido o arquivo
    int custo; 									//Custo atualizado com o menor custo
    int porta;									//Sua porta
    int estado;									//Estado dele, se está morto(0) ou vivo(1)
    char ip[MAX_ADRESS];						//Seu endereço de Ip
}Vizinhos_t;

//Estrutura de distância, para o vetor de distâncias
typedef struct{
  	int dist; 									//Distancia acumulada
  	int p_salto;								//Próximo salto 
}dist_t;

//Estrutura de pacote
typedef struct{
  	int tipo;									//Tipo de pacote, se é de controle(0) ou uma mensagem(1) 
  	int dest;									//Destino do pacote
  	int orig;									//Sua origem
  	char message[TAM_MENSAGEM];					//A mensagem
  	dist_t dist_vector[NROUT];					//Vetor de distancia que esse roteador possui
}Pacote_t;

//Fila de pacotes
typedef struct{
  	pthread_mutex_t mutex;
  	int inicio;
  	int fim;
  	Pacote_t fila[MAX_QUEUE];
}Fila_pacote;


//Escopo das funções utilizadas
void inicializa_vetor_vizinhos(	Vizinhos_t info_vizinhos[NROUT], 
								dist_t t_roteamento[NROUT][NROUT]);

void configura_enlace(	Roteador_t *roteador_info, 
						int lista_vizinhos[NROUT], 
						Vizinhos_t info_vizinhos[NROUT],
						dist_t t_roteamento[NROUT][NROUT]);

void configura_roteador( 	Roteador_t *roteador_info,
							int lista_vizinhos[NROUT],
							dist_t t_roteamento[NROUT][NROUT],
							struct sockaddr_in *si_me,
							Vizinhos_t info_vizinhos[NROUT],
							Fila_pacote *in,
							Fila_pacote *out,
							pthread_mutex_t *log_mutex,
							pthread_mutex_t *messages_mutex,
							pthread_mutex_t *estado_mutex);

void fila_vetor_ditancias(	Fila_pacote *out,
                    		int lista_vizinhos[NROUT],
                    		dist_t t_roteamento[NROUT][NROUT],
                    		Roteador_t roteador_info);

void print_informacoes_vizinhos(	Roteador_t roteador_info, 
                                    int lista_vizinhos[NROUT],
                                    Vizinhos_t info_vizinhos[NROUT], 
        	                       	dist_t t_roteamento[NROUT][NROUT]);

void print_t_roteamento(int id, dist_t t_roteamento[NROUT][NROUT], int lista_vizinhos[]);

void clona_pacote(Pacote_t *a, Pacote_t *b);
void menu(int id);
void die(char* msg);
int toint(char *str);
void print_tabela_roteamento(dist_t t_roteamento[NROUT][NROUT], FILE *file, int infile);
void print_file(FILE *file, pthread_mutex_t *mutex);
void print_barra_caixa_saida();
void timeStamp();

#endif