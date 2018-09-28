/*DICA DE COMPILAÇÃO:
    gcc -c dijkstra.c -o dijkstra.o -Wall
    gcc -c priority_queue.c -o priority_queue.o
    gcc dijkstra.o priority_queue.o -o dijkstra
    ADRIEL SCHMITZ
EXECUÇÃO:
    ./dijkstra <entrada.in
*/
#include <stdio.h>
#include <string.h>
#include "priority_queue.h"

#define ii(a, b) leTemp.first = (a), leTemp.second = (b)
#define it(a, b) pqueue.key = (a), pqueue.value = (b)
#define nVERTICES 7

typedef struct{
  int first, second;
}pair;

pair grafoListaAdj[MAX][MAX], leTemp;

void printDistancias(pair caminho[], int inicio);
void dijkstra(int inicio, int *grau);

int main(void) {
    int u, v, w, inicio, grau[MAX];
    memset(grau, 0, sizeof(grau));
    scanf("%d", &inicio);

    while(scanf("%d %d %d", &u, &v, &w) != EOF){
        ii(v, w);
        grafoListaAdj[u][grau[u]++] = leTemp;
        ii(u, w);
        grafoListaAdj[v][grau[v]++] = leTemp;
    }
    dijkstra(inicio, grau);
    return 0;
}

void dijkstra(int inicio, int *grau){
    int atual, custo;
    pair caminho[MAX];// caminho[].first = proximo salto && caminho[].second = distancia
    type pqueue;
    pair aresta;

    for(int i=0; i<MAX; i++)
        caminho[i].second = INF;

    caminho[inicio].second = 0; // Zera a distancia do vertice atual para ele mesmo
    it(0, inicio);
    push(pqueue);

    while(empty()){
        pqueue = top();
        atual = pqueue.value;
        custo = pqueue.key;
        pop();
        if(custo > caminho[atual].second) 
            continue;
        for(int v=0; v<grau[atual]; v++) {
            aresta = grafoListaAdj[atual][v];
            if((caminho[atual].second+aresta.second) < caminho[aresta.first].second){
                caminho[aresta.first].second = caminho[atual].second + aresta.second;
                it(caminho[aresta.first].second, aresta.first);
                push(pqueue);
            }
        }
    }
    printDistancias(caminho, inicio);
}
void printDistancias(pair caminho[], int inicio){
    printf("Distancias em relação ao vértice %d: \n", inicio);
    printf("|    Destino    |   Prox Salto  |     Custo     |\n");
    for(int w = 0; w<nVERTICES; w++)
        printf("|\t%d\t|\t%d\t|\t%d\t|\n", w, caminho[w].first, caminho[w].second);
}