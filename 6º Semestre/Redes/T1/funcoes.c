#include "roteador.h"
// inicializa o enlace e chama o dijkstra
void configura_enlace(int id, pair tabela_roteamento[]){
    int u, v, w, grau[N_ROUT];
    memset(grau, 0, sizeof(grau));
    // Leitura do enlace ====================================================
    FILE *links = fopen("enlaces.config", "r");
    if(!links) die("Falha ao abrir o arquivo de enlaces\n");
    while(fscanf(links, "%d %d %d\n", &u, &v, &w) != EOF){ // leitura das arestas
        ii(v, w);
        grafoListaAdj[u][grau[u]++] = leTemp;
        ii(u, w);
        grafoListaAdj[v][grau[v]++] = leTemp;
    }
    fclose(links);
    dijkstra(id, tabela_roteamento, grau);
}

void dijkstra(int id, pair tabela_roteamento[], int grau[]){
    int atual, custo, v, caminho[N_ROUT]; // caminho usado para fazer o backtracking
    type pqueue;
    pair aresta;

    for(v=0; v<N_ROUT; v++) 
        tabela_roteamento[v].second = INF; // seta todas as distancias para infinito

    tabela_roteamento[id].second = 0; // Zera a distancia do vertice atual para ele mesmo
    tabela_roteamento[id].first = id; // O próximo salto do vértice atual é ele mesmo
    it(0, id);
    push(pqueue); // insere na fila

    while(empty()){
        pqueue = top();
        atual = pqueue.value;
        custo = pqueue.key;
        pop(); // tira do topo da fila
        if(custo > tabela_roteamento[atual].second) 
            continue;
        for(v=0; v<grau[atual]; v++) {
            aresta = grafoListaAdj[atual][v];
            if((tabela_roteamento[atual].second+aresta.second) < tabela_roteamento[aresta.first].second){
                tabela_roteamento[aresta.first].second = tabela_roteamento[atual].second + aresta.second;
                it(tabela_roteamento[aresta.first].second, aresta.first);
                push(pqueue);
                caminho[aresta.first] = atual;
            }
        }
    }
    for(v=0; v<N_ROUT; v++){
        if(v != id) 
            tabela_roteamento[v].first = backtracking(id, v, caminho);
    }
}
int backtracking(int inicial, int atual, int caminho[]){
    return caminho[atual] == inicial ? atual : backtracking(inicial, caminho[atual], caminho);
}
//configura o roteador com as informações 
void configura_roteador(int id, int *sock, struct sockaddr_in *si_me, router_t roteadores[]){
    FILE *routers_file = fopen("roteador.config", "r");
    if(!routers_file) 
        die("Falha ao abrir o arquivo de roteadores\n");
    for(int i = 0; fscanf(routers_file, "%d %d %s\n", &roteadores[i].id, &roteadores[i].porta, roteadores[i].ip) != EOF; i++);
    fclose(routers_file);

    //Cria o socket(dominio, tipo, protocolo)
    if((*sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1){
        die("Falha ao criar Socket!");
    }
    
    memset((char *) si_me, 0, sizeof(*si_me));
    si_me->sin_family = AF_INET;
    si_me->sin_port = htons(roteadores[id].porta); //Porta em ordem de bytes de rede
    si_me->sin_addr.s_addr = htonl(INADDR_ANY); //Atribui o socket a todo tipo de interface
    //Liga o socket a porta (atribui o endereço ao file descriptor)
    if( bind(*sock, (struct sockaddr*) si_me, sizeof(*si_me)) == -1)
        die("A ligacao do socket com a porta falhou...\n");
}
//Funcao para imprimir mensagens de erro e encerrar o programa
void die(char* msg){
    printf("%s\n", msg);
    exit(1);
};
//Funcao para converter uma string para inteiro
int toint(char *str){
    int i, pot, ans = 0;

    for(i = strlen(str)-1, pot = 1; i >= 0; i--, pot *= 10){
        ans += pot * (str[i] - '0');
    }
    return ans;
}
void print_tabela_roteamento(pair tabela_roteamento[], int id){
    printf("\t+-----------------------------------------------+\n");
    printf("\t|TABELA DE ROTEAMENTO EM RELAÇÃO AO ROTEADOR ["TIPO"]|\n", id+ASCII);
    printf("\t|---------------+---------------+---------------|\n");
    printf("\t|    Destino    | Próximo Salto |     Custo     |\n");
    printf("\t|---------------+---------------+---------------|\n");
    for(int w = 0; w<N_ROUT; w++){
        printf("\t|\t"TIPO"\t|\t"TIPO"\t|\t%d\t|\n", w+ASCII, tabela_roteamento[w].first+ASCII, tabela_roteamento[w].second);
    }
    printf("\t+-----------------------------------------------+\n");
    printf("\n\n\tPressione ENTER para voltar...");
    getchar();
    getchar();
}
void menu(int id, int nova, char LOG[]){
    printf("+----------------------------+----------------------------------+\n");
    printf("|\t\tROTEADOR ["TIPO"] | [%d] NOVAS MENSAGENS\t\t|\n", id+ASCII, nova);
    printf("+----------------------------+----------------------------------+\n");
    printf("| Relatório do LOG: %s\n", LOG);
	printf("+---------------------------------------------------------------+\n");
    printf("|1 - Atualizar\t\t\t\t\t\t\t|\n");
    printf("|2 - Checar Tabela de Roteamento\t\t\t\t|\n");
    printf("|3 - Escrever Mensagem\t\t\t\t\t\t|\n");
    printf("|4 - Ler Mensagens\t\t\t\t\t\t|\n");
    printf("|0 - Sair\t\t\t\t\t\t\t|\n");
    printf("|-> ");
}

void print_caixa_entrada(tipo info_msg, pacote_t pacote[]){
    printf("+---------------------------------------------------------------+\n");
    printf("|\t\t\tCAIXA DE ENTRADA\t\t\t|\n");
    printf("+---------------------------------------------------------------+\n");
    if(!info_msg.qtd_msg){// se a caixa de entrada estiver vázia
        printf("Desculpe, voce ainda não tem mensagens...\n");
    }else{
        for(int i=0; i<info_msg.qtd_msg; i++)
            printf("|REMETENTE ["TIPO"]: %s\n", pacote[i].origem+ASCII, pacote[i].mensagem);
    }
    printf("\n\nPressione ENTER para voltar...");
    getchar();
    getchar();
}
void print_barra_caixa_saida(){
    printf("+---------------------------------------------------------------+\n");
    printf("|\t\t\tCAIXA DE SAÍDA\t\t\t\t|\n");
    printf("+---------------------------------------------------------------+\n");
    printf("Insira o [ID] do roteador que receberá a mensagem:\n-> ");
}