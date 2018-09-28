#include "roteador.h"

pair tabela_roteamento[N_ROUT]; //Tabela de roteamento
pacote_t pacote[BOX_SIZE]; // Caixa de mensagens
router_t info_roteador[N_ROUT]; //Informações sobre os roteadores (i, porta, ip)

char LOG[100];

int main(int argc, char *argv[]){
    int opcao = -1, snum=0;
    pacote_t aux_envio;
    tipo info_msg;
    
    //Trata erros no argumento
    if(argc < 2) die("Argumentos insuficientes, informe o [ID] do roteador a ser instanciado!");
    else if(argc > 2) die("Argumentos demais, informe apenas o [ID] do roteador a ser instanciado!");
    info_msg.id = toint(argv[1]); //converte o argumento para inteiro e passo pro ID
    if(info_msg.id < 0 || info_msg.id >= N_ROUT) die("Não existe um roteador com este [ID]!");

    info_msg.qtd_msg = info_msg.nova = 0;
    info_msg.slen = (int)sizeof(si_me);

    strcpy(LOG, "Não aconteceu nada ainda...");

    configura_enlace(info_msg.id, tabela_roteamento); //Recebe o enlace e aplica o dijkstra
    configura_roteador(info_msg.id, &info_msg.sock, &si_me, info_roteador); // Inicializa o roteador
    
    pthread_create(&receber_id, NULL, receber, &info_msg); //Cria a thread receptora de mensagem

    while(1){
        system("clear");
        switch(opcao){
            case -1:
                menu(info_msg.id, info_msg.nova, LOG);
                while(scanf("%d", &opcao) != 1) 
                    getchar();
                break;
            case 1:
                opcao = -1;
                break;
            case 2:
                print_tabela_roteamento(tabela_roteamento, info_msg.id);
                opcao = -1;
                break;
            case 3:
                print_barra_caixa_saida();
	            while(scanf("%d", &aux_envio.destino) != 1) // Enquanto nao for informado algum número inteiro, nao sai do while
	            	getchar();
            	while(1){
    	            if(aux_envio.destino < 0 || aux_envio.destino >= N_ROUT){
                        printf("\nEsse roteador nao existe!\n");
                        sleep(1);
                        break;
    	            }else{
    	            	system("clear");
    	                getchar();
    	                printf("Insira uma mensagem com no máximo [%d] caracteres!\n-> ", MENSAGEM_SIZE);
    	                scanf("%[^\n]", aux_envio.mensagem);
    	                if(strlen(aux_envio.mensagem) <= MENSAGEM_SIZE){ // verifica se a mensagem é maior que o tamanho padrão
    		                aux_envio.origem = info_msg.id;
    		                aux_envio.numero = snum++;//numero da mensagem
                            enviar_pacote(aux_envio, info_msg.sock, info_msg.slen, 0);
                            printf("\nPacote enviado!\n");
    		            	sleep(2);
    		            	opcao = -1;
    		            	break;
    		            }else{
    		            	printf("\nMENSAGEM EXCEDE O TAMANHO MÁXIMO DE CARACTERES!\n");
    		            	sleep(3);
    		            	system("clear");
    	            	}
    	            }
                }
                break;
            case 4:
                info_msg.nova = 0;
                print_caixa_entrada(info_msg, pacote);
                opcao = -1;
                break;
            case 0:
    			exit(1);
                break;
            default:
                system("clear");
                printf("\tOPÇÃO INVÁLIDA! \nInforme uma opção existente no menu!\n");
                sleep(3);
                opcao = -1;
                break;
        }
    }
}

void *receber(void *t){ // Thread que fica escutando pra ver se chegou alguma nova mensagem
    tipo *info_msg = (tipo*)t;
    pacote_t aux_recebimento;
    char c[2]; c[1] = 0;

    while(1){
        //Recebe do socket(socket, dados, tamanho dos dados, flags, endereço, tamanho do endereço)
        if(recvfrom(info_msg->sock, &aux_recebimento, sizeof(aux_recebimento), 0, (struct sockaddr*) &si_me, (uint*)&info_msg->slen) == -1){
            printf("\tErro ao receber pacote\n");
        }else{
            if(aux_recebimento.destino == info_msg->id){ // verifica se o pacote nao é pra esse roteador
                info_msg->nova++;
                pacote[info_msg->qtd_msg++] = aux_recebimento; //incrementa a quantidade de mensagem recebidas
                strcpy(LOG, "pacote recebido do roteador #");
                c[0] = aux_recebimento.origem + ASCII;
                strcat(LOG, c);
            }else{ //se nao for, encaminha o pacote para o roteador de destino
                enviar_pacote(aux_recebimento, info_msg->sock, info_msg->slen, 1);
            }
        }
    }
}
void enviar_pacote(pacote_t aux_pacote, int sock, int slen, int flag){
    char c[2];
    int destino;
    c[1] = 0;

    destino = tabela_roteamento[aux_pacote.destino].first; // pega o próximo salto da tabela na posição do destino
    si_me.sin_port = htons(info_roteador[destino].porta); // atribui a porta de destino
    if(inet_aton(info_roteador[destino].ip , &si_me.sin_addr) == 0){
        printf("Falha ao obter endereco do destinatario, verifique o arquivo roteador.config...\n");
    }else{
        //Envia para o socket requisitado(socket, dados, tamanho dos dados, flags, endereço, tamanho do endereço)
        if(sendto(sock, &aux_pacote, sizeof(aux_pacote), 0, (struct sockaddr*) &si_me, slen) == -1){
            printf("Falha ao enviar pacote...\n");
        }else{
            strcpy(LOG, "pacote #");
            c[0] = aux_pacote.numero + '0';
            strcat(LOG, c);
            if(flag){ // significa que é pra enviar, nao veio de nenhum roteador
                strcat(LOG, " vindo de #");
                c[0] = aux_pacote.origem + ASCII;
                strcat(LOG, c);
            }
            strcat(LOG, " encaminhado para #");
            c[0] = aux_pacote.destino + ASCII;
            strcat(LOG, c);
            strcat(LOG, " via #");
            c[0] = tabela_roteamento[aux_pacote.destino].first + ASCII;
            strcat(LOG, c);
        }
    }
}