/*	UNIVERSIDADE FEDERAL DA PRONTEIRA SUL - UFFS
	ADRIEL SCHMITZ e MAICON BRANDÃO
	TRABALHO NP1 - ESTRUTURA DE DADOS - 2016/02
	CIÊNCIA DA COMPUTAÇÃO
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "declaracoes_funcoes.h"

int main(){
	TppecaDomino *monte, *jogador, *aux, *bot, *mesa, *pecajogada;
	int i, cont = 0, cont2 = 0, escolha_lado, numero_pecas, random, aux_tamanho;
	monte = jogador = aux = bot = mesa = pecajogada = inicializa();
	srand(clock());

 //BLOCO QUE CONSTROI A PARTE OBRIGATÓRIA DO JOGO---------------------------------------------------------------------------------
	monte = cria_pecas();
	while(cont < 6){ //Distribuição de 6 peças para o jogador.
		i = abs(rand()%(28-cont));
		aux = copiar(monte, i);
		jogador = insere_fim(jogador, aux->numberLeft, aux->numberRight);
		cont++;
		monte = excluir(monte, aux->numberLeft, aux->numberRight);
	}
	while(cont2 < 6){ //Distribuição de 6 peças para o bot.
		i = abs(rand()%(22-cont));
		aux = copiar(monte, i);
		bot = insere_fim(bot, aux->numberLeft, aux->numberRight);
		cont2++;
		monte = excluir(monte, aux->numberLeft, aux->numberRight);
	}
	i = abs(rand()%16); //Insere uma peça aleatória na mesa para o início do jogo.
	aux = copiar(monte, i);
	mesa = insere_fim(mesa, aux->numberLeft, aux->numberRight);
	monte = excluir(monte, aux->numberLeft, aux->numberRight); // monte rece 15 peças restantes para a compra
 //FIM DA SEPARAÇÃO DAS PEÇAS INICIAIS------------------------------------------------------------------------------------------

 //BLOCO DA VEZ DO JOGADOR---------------------------------------------------------------------------------------------------
	system("reset");
	TppecaDomino *aux_mao_bot = bot;
	int flag_jogo_rodando = 1, flag_jogador_ativo = 1;
	do{
		while(flag_jogador_ativo){
			imprime_info(mesa, jogador, bot, monte);
			printf("MESA\n");
			imprime(mesa);
			printf("MÃO DO JOGADOR\n");
			imprime(jogador);
		 	int opcao_peca_escolhida;
			numero_pecas = contar_elementos(jogador);
			printf("\nInforme a peça que deseja jogar ou [0] para comprar: ");
			while(scanf("%d", &opcao_peca_escolhida) != 1) getchar();//Só para de ler entradas enquanto o usuário nao informar um inteiro
			if(opcao_peca_escolhida >= 1 && opcao_peca_escolhida <= numero_pecas && numero_pecas != 0){
				pecajogada = jogador;
				for(i = 1; i<opcao_peca_escolhida; i++){ 
					pecajogada = pecajogada->right; 
				}
				opcao_peca_escolhida = valida_jogada(mesa, pecajogada);
				if(opcao_peca_escolhida == 1){
					mesa = insere_mesa(mesa, pecajogada, 0);
					jogador = remove_peca_jogada(jogador, pecajogada);
					imprime_info(mesa, jogador, bot, monte);
					printf("MESA\n");
					imprime(mesa);
					printf("MÃO DO JOGADOR\n");
					imprime(jogador);
					flag_jogador_ativo = 0;
				}else if(opcao_peca_escolhida == 2){
					int flag_escolhe_lado = 1;
					while(flag_escolhe_lado){
						printf("Em qual lado da mesa deseja inserir a peça?\nEsquerdo[1] | Direito[2]: ");
						while(scanf("%d", &escolha_lado) != 1) getchar();
						if(escolha_lado == 1){
							mesa = insere_mesa(mesa, pecajogada, 1);
							jogador = remove_peca_jogada(jogador, pecajogada);
							imprime_info(mesa, jogador, bot, monte);
							printf("MESA\n");
							imprime(mesa);
							printf("MÃO DO JOGADOR\n");
							imprime(jogador);
							flag_jogador_ativo = 0;
							break;
						}else if(escolha_lado == 2){
							mesa = insere_mesa(mesa, pecajogada, 2);
							jogador = remove_peca_jogada(jogador, pecajogada);
							imprime_info(mesa, jogador, bot, monte);
							printf("MESA\n");
							imprime(mesa);
							printf("MÃO DO JOGADOR\n");
							imprime(jogador);
							flag_jogador_ativo = 0;
							break;
						}else{
							printf("\tERROR. Escolha somente 1 ou 2.\n");						
						}									
					}
				}else{
					if(testa_pecas(jogador, mesa) == 1){
						system("clear");
						printf("\tPEÇA INVÁLIDA!\n");
						sleep(1);
					}else if(testa_pecas(jogador, mesa) == 0 && monte != NULL){
						printf("\nVocê não possui peças válidas. Digite [0] para comprar no monte.\n");
						sleep(3);
					}else{
						system("clear");
						printf("\tAVISO:\nVocê não tem mais peças válidas para esse turno e o monte está vazio.\n");
						sleep(3);
						flag_jogador_ativo = 0;
					}			
				}
			}else if(opcao_peca_escolhida == 0){
				if(contar_elementos(monte) > 0){
					int pesca_escolha = 0;
					do{
						system("clear");
						while(pesca_escolha != 0 && pesca_escolha != 1){
							printf("Opção inválida. Pescar[0] | Cancelar[1]\n");
							while(scanf("%d", &pesca_escolha) != 1) getchar();
						}
						if(pesca_escolha == 1){
							break;
						}
						aux_tamanho = contar_elementos(monte);
						random = abs(rand()%(aux_tamanho));
						aux = copiar(monte, random);
						jogador = insere_fim(jogador, aux->numberLeft, aux->numberRight);
						monte = excluir(monte, aux->numberLeft, aux->numberRight);
						imprime_info(mesa, jogador, bot, monte);
						printf("MESA\n");
						imprime(mesa);
						printf("MÃO DO JOGADOR\n");
						imprime(jogador);
						if(monte){
							printf("Continuar pescando?\nSim[0] | Não[1]: \n");
							scanf("%d", &pesca_escolha);
							if(pesca_escolha != 0 && pesca_escolha != 1){
								printf("ERROR.\nEscolha 0 para pescar ou 1 para cancelar.\n: ");
								sleep(2);
							}
						}else{
							free(monte);
							break;					
						}		
					}while(pesca_escolha != 1);				
				} else {
					system("clear");
					printf("Erro. [0] PEÇAS NO MONTE!.\n");
					sleep(2);
				}		
			}else{
				system("clear");
				printf("\tERROR.\nInsira um índice entre 1 a [%d].\n", numero_pecas);
				sleep(2);
			}			
		}
		if(jogador == NULL){ // caso o jogador nao estiver mais peças na mao, o bot nao precisa jogar mais;
			break;
		}
	 //FECHA O WHILE DA flag_jogador_ativo, PASSANDO A VEZ PARA O BOT--------------------------------------------

	 //BLOCO DO BOT JOGAR--------------------------------------------------------------------------------------
		aux_mao_bot = bot;
		while(valida_jogada(mesa, aux_mao_bot) == 0 && aux_mao_bot->right != NULL){
			aux_mao_bot = aux_mao_bot->right;				
		}
		while(monte != NULL && valida_jogada(mesa, aux_mao_bot) == 0){ // enquanto o monte tiver peças, o bot vai tentar comprar...
			while(valida_jogada(mesa, aux_mao_bot) == 0){
				aux_tamanho = contar_elementos(monte);
				random = abs(rand()%(aux_tamanho));
				aux = copiar(monte, random);
				bot = insere_fim(bot, aux->numberLeft, aux->numberRight);
				monte = excluir(monte, aux->numberLeft, aux->numberRight);
				aux_mao_bot = aux_mao_bot->right;			
			}
		}
		if(valida_jogada(mesa, aux_mao_bot) != 0){
			aux_mao_bot = bot;		
		}
	    //Se a função, valida_jogada retornar algum valor, significa que alguma peça pode ser inserida	
	    while(valida_jogada(mesa, aux_mao_bot) == 0 && aux_mao_bot->right != NULL){
			aux_mao_bot = aux_mao_bot->right;				
		}
		if(valida_jogada(mesa, aux_mao_bot) != 0){
			mesa = insere_mesa(mesa, aux_mao_bot, 0);
			bot = remove_peca_jogada(bot, aux_mao_bot);			
		}
		if(bot == NULL){ // Caso o bot nao tenha mais peças na mao, para o while do jogo, parindo pra contagem dos pontos...
			break;
		}else if(valida_jogada(mesa, jogador) == 0 && monte == NULL){
			break;
		}
	 //FIM DA VEZ DO BOT--------------------------------------------------------------------------------------------
		flag_jogador_ativo = 1;
	}while(flag_jogo_rodando);// fecha o while da flag_jogo_rodando, encerrando o jogo
  //----------------------------------------------------------------------------------------------------------------	
	quem_ganhou(jogador, bot, monte); // Define o vencedor;

	return 0;
}
