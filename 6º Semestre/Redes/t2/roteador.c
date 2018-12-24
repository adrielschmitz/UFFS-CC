#include "funcoes.h"

Roteador_t roteador_info;				//Estrutura contendo as informações importante que cada roteador possui
int lista_vizinhos[NROUT]; 				//Lista de vizinhos do roteador
struct sockaddr_in si_me;				//Estrutura de endereço do roteador e outro usado para envios
int slen = sizeof(si_me);		 		//Tamanho do endereço
Vizinhos_t info_vizinhos[NROUT]; 		//Informacoes dos vizinhos (custo, porta, endereco)
dist_t t_roteamento[NROUT][NROUT]; 		//Tabela de roteamento do nó
Fila_pacote in, out; 					//Filas de entrada e saida de pacotes

void *atualizar(void *nothing); 		//Thread responsavel por enfileirar periodicamente pacotes de distancia para todos os vizinhos
void *enviar(void *nothing); 			//Thread responsavel por enviar pacotes
void *receber(void *nothing); 			//Thread responsavel por receber pacotes
void *desempacotar(void *nothing); 		//Thread responsavel por desembrulhar pacotes e trata-los
void *verificar_enlace(void *nothing); 	//Thread responsavel por verificar se os nós vizinhos estão vivos
int escolha_menu(); 					//Retorna o inteiro escolhido pelo usuário

int main(int argc, char *argv[]){
    int opcao = -1;
    char caminho_log[20] = "./logs/log";
    char caminho_mensagem[25] = "./messages/message";
    Pacote_t pacote;

    // Certifica-se que os argumentos são válidos ao iniciar o programa
    if(argc < 2)
        die("Argumentos insuficientes, informe o ID do roteador a ser instanciado");
    if(argc > 2)
        die("Argumentos demais, informe apenas o ID do roteador a ser instanciado");
    roteador_info.id = toint(argv[1]); // Inicializa variável global com o ID do processo
    if(roteador_info.id < 0 || roteador_info.id >= NROUT) 
        die("Não existe um roteador com este id, confira o arquivo de configuração");

    //Adiciona id do roteador ao caminho dos arquivos de mensagem e log
    strcat(caminho_log, argv[1]);
    strcat(caminho_mensagem, argv[1]);

    printf("%s\n", caminho_mensagem);
    //Cria o arquivo para armazenar os logs
    if(!(logs = fopen(caminho_log, "w+"))) 
        die("Falha ao criar arquivo de log");

    //Cria o arquivo para armazenar as mensagens
    if(!(messages = fopen(caminho_mensagem, "w+"))) 
        die("Falha ao criar arquivo de mensagens");

    //Rotina de inicializacao do roteador
    configura_enlace(	&roteador_info,
    					lista_vizinhos, 
    					info_vizinhos,
    					t_roteamento);

    configura_roteador(	&roteador_info,
    					lista_vizinhos,
    					t_roteamento,
    					&si_me, 
    					info_vizinhos,
    					&in,
    					&out,
    					&log_mutex,
    					&messages_mutex,
    					&estado_mutex);

    pthread_create(&enviar_id, NULL, enviar, NULL); //Cria thread emitidora
    pthread_create(&receber_id, NULL, receber, NULL); //Cria thread receptora
    pthread_create(&desempacotar_id, NULL, desempacotar, NULL); //Cria thread desempacotadora
    pthread_create(&atualizar_id, NULL, atualizar, NULL); //Cria thread atualizadora

    while(1){
        system("clear");
        switch(opcao){
            case -1:
                menu(roteador_info.id);
                while(scanf("%d", &opcao) != 1) 
                    getchar();
                break;
            case 1:
                print_informacoes_vizinhos(roteador_info, lista_vizinhos, info_vizinhos, t_roteamento);
                opcao = -1;
                break;
            case 2:
                printf("+----------------------------+----------------------------------+\n");
                printf("|\t\tTABELA DE ROTEAMENTO DO ROTEADOR [%d]\t\t|\n", roteador_info.id);
                printf("+---------------------------------------------------------------+\n");
                print_tabela_roteamento(t_roteamento, NULL, 0);
                printf("\n\n\tPressione ENTER para voltar...");
                getchar();
                getchar();
                opcao = -1;
                break;
            case 3:
                printf("------------------------LOG------------------------\n");
                print_file(logs, &log_mutex);
                printf("\n-----------------------FIM------------------------\n");
                printf("\n\nPressione ENTER para voltar...");
                getchar();
                getchar();
                opcao = -1;
                break;
            case 4:
                printf("---------------------MENSAGENS----------------------\n");
                print_file(messages, &messages_mutex);
                printf("\n-----------------------FIM-------------------------\n");
                printf("\n\nPressione ENTER para voltar...");
                getchar();
                getchar();
                opcao = -1;
                break;
            case 5:
                print_barra_caixa_saida();
                while(scanf("%d", &pacote.dest) != 1) // Enquanto nao for informado algum número inteiro
                    getchar();
                while(1){
                    if(pacote.dest < 0 || pacote.dest >= NROUT){
                        printf("\nEsse roteador nao existe!\n");
                        sleep(1);
                        break;
                    }else{
                        system("clear");
                        getchar();
                        printf("Insira uma mensagem com no máximo [%d] caracteres!\n-> ", TAM_MENSAGEM);
                        scanf("%[^\n]", pacote.message);
                        if(strlen(pacote.message) <= TAM_MENSAGEM){ // verifica se a mensagem é maior que o tamanho padrão
                            pacote.tipo = 0;
                            pacote.orig = roteador_info.id;
                            //strcpy(pacote.message, message);
                            pthread_mutex_lock(&out.mutex);
                            clona_pacote(&pacote, &out.fila[out.fim++]); //Enfilera o novo pacote na fila de saida
                            pthread_mutex_unlock(&out.mutex);
                            printf("\nPacote enviado!\n");
                            sleep(2);
                            opcao = -1;
                            break;
                        }else{
                            printf("\nMENSAGEM EXCEDE O TAMANHO MÁXIMO DE CARACTERES!\n");
                            sleep(3);
                        }
                    }
                }
                break;
            case 0:
                //Fecha sockets e arquivos
                close(roteador_info.sock);
                fclose(logs);
                fclose(messages);
                exit(1);
                break;
            default:
                printf("\tOPÇÃO INVÁLIDA! \nInforme uma opção existente no menu!\n");
                sleep(3);
                opcao = -1;
                break;
        }
    }
    return 0;
}

int escolha_menu() {
    int opcao;
    while(scanf("%d", &opcao) != 1){
        getchar();
    }
    return opcao;
}

void* enviar(void *nothing){
    int new_dest;
    Pacote_t *pacote;

    pthread_mutex_lock(&log_mutex);
    fprintf(logs, "[ENVIAR] Enviador iniciado!\n");
    pthread_mutex_unlock(&log_mutex);
    while(1){
        pthread_mutex_lock(&out.mutex);
        while(out.inicio != out.fim){
            pacote = &(out.fila[out.inicio]); //Aponta o pacote a ser enviado
            new_dest = t_roteamento[roteador_info.id][pacote->dest].p_salto; //Pega o próximo destino
            si_me.sin_port = htons(info_vizinhos[new_dest].porta); //Atribui a porta do pacote a ser enviado
            if (inet_aton(info_vizinhos[new_dest].ip , &si_me.sin_addr) == 0){
                pthread_mutex_lock(&log_mutex);
                fprintf(logs, "[ENVIAR] Falha ao obter endereco do destinatario\n");
                pthread_mutex_unlock(&log_mutex);
            }else{
                //Envia para o socket requisitado(socket, dados, tamanho dos dados, flags, endereço, tamanho do endereço)
                if(sendto(roteador_info.sock, pacote, sizeof(*pacote), 0, (struct sockaddr*) &si_me, slen) == -1){
                    pthread_mutex_lock(&log_mutex);
                    fprintf(logs, "[ENVIAR] Falha ao enviar Pacote de %s ao nó %d\n"
                    ,out.fila[out.inicio].tipo ? "controle" : "dados", out.fila[out.inicio].dest);
                    pthread_mutex_unlock(&log_mutex);
                }else{
                    if (!pacote->tipo){
                        pthread_mutex_lock(&log_mutex);
                        fprintf(logs, "[ENVIAR] Pacote de %s enviado com sucesso para o nó %d\n"
                        ,out.fila[out.inicio].tipo ? "controle" : "dados", out.fila[out.inicio].dest);
                        pthread_mutex_unlock(&log_mutex);
                    }
                }
            }
            out.inicio++;
        }
        pthread_mutex_unlock(&out.mutex);
    }
}

void* desempacotar(void *nothing){
    int i, flag_retransmitir, flag_alteracao;
    Pacote_t *pacote;
    pthread_mutex_lock(&log_mutex);
    fprintf(logs, "[DESEMPACOTAR] Desempacotador iniciado!\n");
    pthread_mutex_unlock(&log_mutex);

    while(1){
        pthread_mutex_lock(&in.mutex);
        while(in.inicio != in.fim){
            pacote = &in.fila[in.inicio];
            if(pacote->dest == roteador_info.id){ //Se o pacote é pra mim
                //printf("se é mensagem\n");
                if(pacote->tipo == 0){
                    pthread_mutex_lock(&log_mutex);
                    fprintf(logs, "[DESEMPACOTAR] Processando pacote de %s vindo de %d\n",
                    pacote->tipo ? "controle" : "mensagem", pacote->orig);
                    pthread_mutex_unlock(&log_mutex);
                    pthread_mutex_lock(&messages_mutex);
                    fprintf(messages, "Roteador %d: ", pacote->orig);
                    fprintf(messages, "%s", pacote->message);
                    pthread_mutex_unlock(&messages_mutex);
                }else{
                    //Marca que ouviu falar dele
                    pthread_mutex_lock(&estado_mutex);
                    info_vizinhos[pacote->orig].estado = 1;
                    pthread_mutex_unlock(&estado_mutex);
                    for(i = flag_retransmitir = flag_alteracao = 0; i < NROUT; i++){
                        //Se o vetor de distancias que o no enviou eh diferente do o no possui, atualiza
                        if(t_roteamento[pacote->orig][i].dist != pacote->dist_vector[i].dist ||
                            t_roteamento[pacote->orig][i].p_salto != pacote->dist_vector[i].p_salto || info_vizinhos[pacote->orig].estado == -1){
                            t_roteamento[pacote->orig][i].dist = pacote->dist_vector[i].dist;
                            t_roteamento[pacote->orig][i].p_salto = pacote->dist_vector[i].p_salto;
                            flag_alteracao = 1;
                            //Se a distancia ate o destino, mais o custo ate o no for maior do que ja tem
                            if(pacote->dist_vector[i].dist + info_vizinhos[pacote->orig].custo < t_roteamento[roteador_info.id][i].dist){
                                t_roteamento[roteador_info.id][i].dist = pacote->dist_vector[i].dist + info_vizinhos[pacote->orig].custo;
                                t_roteamento[roteador_info.id][i].p_salto = pacote->orig;
                                flag_retransmitir = 1;
                            }
                        }            
                    }
                    if(flag_alteracao){
                        pthread_mutex_lock(&log_mutex);
                        fprintf(logs, "[DESEMPACOTAR] A tabela foi atualizada:\n");
                        timeStamp();
                        print_tabela_roteamento(t_roteamento, logs, 1);
                        fprintf(logs,"\n");
                        pthread_mutex_unlock(&log_mutex);
                    }
                    if(flag_retransmitir){
                        //printf("flag_retransmitirindo pacote de atualização do vetor de distancia\n");
                        pthread_mutex_lock(&log_mutex);
                        fprintf(logs, "[DESEMPACOTAR] O vetor de distancias mudou, enfileirando atualização pros vizinhos.\n");
                        fila_vetor_ditancias(&out, lista_vizinhos, t_roteamento, roteador_info);
                        pthread_mutex_unlock(&log_mutex);
                    }
                }
            }else{
                pthread_mutex_lock(&log_mutex);
                fprintf(logs, "[DESEMPACOTAR] Roteando pacote com origem %d, para %d, via %d\n", pacote->orig, pacote->dest, t_roteamento[roteador_info.id][pacote->dest].p_salto);
                pthread_mutex_unlock(&log_mutex);
                
                pthread_mutex_lock(&out.mutex);
                clona_pacote(pacote, &out.fila[out.fim++]); //Enfilero ele na fila de saida
                pthread_mutex_unlock(&out.mutex);
            }
            in.inicio++;
        }
        pthread_mutex_unlock(&in.mutex);
    }
}

void* receber(void *nothing){
    Pacote_t recebido;

    pthread_mutex_lock(&log_mutex);
    fprintf(logs, "[RECEBER] Receptor iniciado!\n");
    pthread_mutex_unlock(&log_mutex);

    while(1){
        if((recvfrom(roteador_info.sock, &recebido, sizeof(recebido), 0, (struct sockaddr *) &si_me, (socklen_t * restrict ) &slen)) == -1) {
            printf("Endereço: %d \n", roteador_info.sock);
            printf("[RECEBER] Erro ao receber pacote\n");
            continue;
        }
        if(!recebido.tipo){
            pthread_mutex_lock(&log_mutex);
            fprintf(logs, "[RECEBER] Pacote recebido de %d\n", recebido.orig);
            pthread_mutex_unlock(&log_mutex);
        }
        pthread_mutex_lock(&in.mutex);
        clona_pacote(&recebido, &in.fila[in.fim++]); //Coloca o pacote no final da fila de recebidos
        pthread_mutex_unlock(&in.mutex);
    }
}
void *atualizar(void *nothing){
    while(1){
        fila_vetor_ditancias(&out, lista_vizinhos, t_roteamento, roteador_info);
        sleep(TOLERANCIA);
    }
}

