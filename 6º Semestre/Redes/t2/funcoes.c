#include "funcoes.h"

//Funcao para imprimir mensagens de erro e encerrar o programa
void die(char* msg){
  printf("%s\n", msg);
  exit(1);
};

//Funcao para converter uma string para inteiro
int toint(char *str){
  	int i, pot, ans;
  	ans = 0;
  	for(i = strlen(str) - 1, pot = 1; i >= 0; i--, pot *= 10)
    	ans += pot * (str[i] - '0');
  	return ans;
}

//Função com rotina de inicialização dos roteadores
void configura_enlace(	Roteador_t *roteador_info, 
						int lista_vizinhos[NROUT], 
						Vizinhos_t info_vizinhos[NROUT],
						dist_t t_roteamento[NROUT][NROUT]){
	int u, v, w;
    //Abre o arquivo de enlaces, carrega informações sobre seus vizinhos
    inicializa_vetor_vizinhos(	info_vizinhos, 
    							t_roteamento);
    
    FILE *links_file = fopen("enlaces.config", "r");
    if (!links_file) die("Falha ao abrir arquivo de enlaces");
    while(fscanf(links_file, "%d %d %d\n", &u, &v, &w) != EOF){
        if (v == roteador_info->id){
            v = u; 
            u = roteador_info->id;
        }
        if(u == roteador_info->id){
            lista_vizinhos[roteador_info->n_vizinhos++] = v;
            info_vizinhos[v].id = v;
            info_vizinhos[v].custo = info_vizinhos[v].custo_original = w;
        }
    }
    fclose(links_file);
}
void inicializa_vetor_vizinhos(	Vizinhos_t info_vizinhos[NROUT], dist_t t_roteamento[NROUT][NROUT]){
	int i, j;
    //Inicializa o vetor de informações de vizinhos e a tabela de roteamento
    for(i=0; i<NROUT; i++){
        info_vizinhos[i].estado = 0;
        info_vizinhos[i].id = info_vizinhos[i].porta = -1;
        info_vizinhos[i].custo = INF;
        for(j = 0; j < NROUT; j++){
            t_roteamento[i][j].dist = INF;
            t_roteamento[i][j].p_salto = -1;
        }
    }
}

void configura_roteador( 	Roteador_t *roteador_info,
							int lista_vizinhos[NROUT],
							dist_t t_roteamento[NROUT][NROUT],
							struct sockaddr_in *si_me,
							Vizinhos_t info_vizinhos[NROUT],
							Fila_pacote *in,
							Fila_pacote *out,
							pthread_mutex_t *log_mutex,
							pthread_mutex_t *messages_mutex,
							pthread_mutex_t *estado_mutex){
	int new_id, new_port, i, u, v;
    char tmp[MAX_ADRESS];

	//Abre o arquivo de roteadores, e Le dele a porta e o fimereço do roteador
    FILE *routers_file = fopen("roteador.config", "r");
    if (!routers_file) 
    	die("Falha ao abrir arquivo de roteadores");

    while(fscanf(routers_file, "%d %d %s\n", &new_id, &new_port, tmp) != EOF){
        if(new_id == roteador_info->id){
        	roteador_info->porta = new_port;
        	strcpy(roteador_info->ip, tmp);
        }
        if(info_vizinhos[new_id].id != -1){
            info_vizinhos[new_id].porta = new_port;
            strcpy(info_vizinhos[new_id].ip, tmp);
        }
    }
    fclose(routers_file);

    //Cria o socket(dominio, tipo, protocolo)
    if((roteador_info->sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
        die("Falha ao criar Socket\n");

    //Inicializa fimereços de estrutura
    memset((char *) si_me, 0, sizeof(*si_me)); //Zera a estrutura
    si_me->sin_family = AF_INET; //Familia
    si_me->sin_port = htons(roteador_info->porta); //Porta em ordem de bytes de rede
    si_me->sin_addr.s_addr  = htonl(INADDR_ANY); //Atribui o socket a todo tipo de interface

    //Liga o socket a porta (atribui o fimereço ao file descriptor)
    if(bind(roteador_info->sock , (struct sockaddr*) si_me, sizeof(*si_me)) == -1)
        die("A ligacao do socket com a porta falhou\n");

    t_roteamento[roteador_info->id][roteador_info->id].dist = 0;
    t_roteamento[roteador_info->id][roteador_info->id].p_salto = roteador_info->id;

    //Preenche o vetor de distâncias inicial do nó
    for(i = 0; i < roteador_info->n_vizinhos; i++){
        u = roteador_info->id; 
        v = lista_vizinhos[i];
        t_roteamento[u][v].dist = info_vizinhos[v].custo;
        t_roteamento[u][v].p_salto = info_vizinhos[v].id;
    }

    //Inicializa as filas de entrada e saida
    in->inicio = out->inicio = in->fim = out->fim = 0;
    pthread_mutex_init(&(in->mutex), NULL);
    pthread_mutex_init(&(out->mutex), NULL);

    //Inicializa mutex dos arquivos de log e mensagens e de checagem de queda de nó
    pthread_mutex_init(log_mutex, NULL);
    pthread_mutex_init(messages_mutex, NULL);
    pthread_mutex_init(estado_mutex, NULL);
}

//Imprime informações sobre o roteador
void print_informacoes_vizinhos(  Roteador_t roteador_info, 
                            int lista_vizinhos[NROUT],
                            Vizinhos_t info_vizinhos[NROUT], 
                            dist_t t_roteamento[NROUT][NROUT]){
    printf("|\t\t\tROTEADOR [%d]\t\t\t\t\t|\n", roteador_info.id);
    printf("|-----------------------------------------------------------------------|\n");
    printf("|\t\tInformações sobre seus vizinhos [Possui: %d]\t\t|\n", roteador_info.n_vizinhos);
    printf("|-----------------------------------------------------------------------|\n");
    printf("|\tId\t|\tCusto\t|\t Porta\t\t|\tIp \t|\n");
    printf("|-----------------------------------------------------------------------|\n");
    for(int i=0; i < roteador_info.n_vizinhos; i++){
        printf("|\t%d\t|\t%d\t|\t %d\t\t|   %s\t|\n",   lista_vizinhos[i],
                                                        t_roteamento[roteador_info.id][lista_vizinhos[i]].dist, 
                                                        info_vizinhos[lista_vizinhos[i]].porta, 
                                                        info_vizinhos[lista_vizinhos[i]].ip);
    }
    printf("|-----------------------------------------------------------------------|\n\n");
    printf("\n\nPressione ENTER para voltar...");
    getchar();
    getchar();
}
//Copia o pacote a para o pacote b
void clona_pacote(Pacote_t *a, Pacote_t *b){
    int i;

    b->tipo = a->tipo;
    b->dest = a->dest;
    b->orig = a->orig;
    strcpy(b->message, a->message);

    for(i = 0; i < NROUT; i++){
        b->dist_vector[i].dist = a->dist_vector[i].dist;
        b->dist_vector[i].p_salto = a->dist_vector[i].p_salto;
    }
}

//Enfilera um pacote para cada vizinho do nó, contfimo seu vetor de distancia
void fila_vetor_ditancias(Fila_pacote *out,
                    int lista_vizinhos[NROUT],
                    dist_t t_roteamento[NROUT][NROUT],
                    Roteador_t roteador_info) {
    int i, j;

    pthread_mutex_lock(&(out->mutex));
    for(i = 0; i < roteador_info.n_vizinhos; i++, out->fim++){
        Pacote_t *pck = &(out->fila[out->fim]);
        pck->tipo = 1;
        pck->orig = roteador_info.id;
        pck->dest = lista_vizinhos[i];
        //printf("Enfileirando pacote de vetor de distancia para o destino %d\n", pck->dist);
        //printf("Vetor de distancia enviado: ");
        for(j = 0; j < NROUT; j++){
            pck->dist_vector[j].dist = t_roteamento[roteador_info.id][j].dist;
            pck->dist_vector[j].p_salto = t_roteamento[roteador_info.id][j].p_salto;
            //printf("(%d,%d) ", pck->dist_vector[j].dist, pck->dist_vector[j].p_salto);
        }
    }
    pthread_mutex_unlock(&(out->mutex));
}

//Funcao que imprime a tabela de roteamento
void print_tabela_roteamento(dist_t t_roteamento[NROUT][NROUT], FILE *file, int infile){
    int i, j;

    if(infile) fprintf(file, "   ");
    else printf("   ");

    for(i = 0; i < NROUT; i++){
        if (infile) 
            fprintf(file, "  %d %s|",i, i > 0 ? "    " : "  ");
        else 
            printf("   %d%s|", i, i > 0 ? "    " : "   ");
    }
    if(file) 
        fprintf(file, "\n");
    else 
        printf("\n");

    for(i = 0; i < NROUT; i++){
        if(file) 
            fprintf(file, "%d |", i);
        else 
            printf("%d |", i);
        for(j = 0; j < NROUT; j++){
            if(infile){
                if(t_roteamento[i][j].dist != INF) 
                    fprintf(file, "[%d]-(%d)| ", t_roteamento[i][j].dist, t_roteamento[i][j].p_salto);
                else 
                    fprintf(file, "    X   | ");
            }else{
                if(t_roteamento[i][j].dist != INF) 
                    printf("[%d]-(%d)| ", t_roteamento[i][j].dist, t_roteamento[i][j].p_salto);
                else 
                    printf("   X   | ");
            }
        }
        if(file)
            fprintf(file, "\n");
        else
            printf("\n");
    }
}

void timeStamp(){
  time_t     now;
  struct tm  ts;
  char       buf[80];
  
  // Get current time
  time(&now);

  // Format time, "ddd yyyy-mm-dd hh:mm:ss zzz"
  ts = *localtime(&now);
  strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S %Z", &ts);
  fprintf(logs, "|%38s%12s", buf, "|\n\n");
}


void menu(int id){
    printf("+----------------------------+----------------------------------+\n");
    printf("|\t\t\tROTEADOR [%d]\t\t\t\t|\n", id);
    printf("+---------------------------------------------------------------+\n");
    printf("|1 - Exibir informações sobre o Roteador\t\t\t|\n");
    printf("|2 - Checar Tabela de Roteamento\t\t\t\t|\n");
    printf("|3 - Checar Log\t\t\t\t\t\t\t|\n");
    printf("|4 - Ler Mensagens\t\t\t\t\t\t|\n");
    printf("|5 - Escrever Mensagem\t\t\t\t\t\t|\n");
    printf("|0 - Sair\t\t\t\t\t\t\t|\n");
    printf("|-> ");
}

void print_barra_caixa_saida(){
    printf("+---------------------------------------------------------------+\n");
    printf("|\t\t\tCAIXA DE SAÍDA\t\t\t\t|\n");
    printf("+---------------------------------------------------------------+\n");
    printf("Insira o [ID] do roteador que receberá a mensagem:\n-> ");
}

void print_file(FILE *file, pthread_mutex_t *mutex){
    char str[100];
    pthread_mutex_lock(mutex);
    fseek(file, 0, SEEK_SET);
    while(fgets(str, 100, file)){
        printf("%s", str);
    }
    fseek(file, 0, SEEK_END);
    pthread_mutex_unlock(mutex);
}

