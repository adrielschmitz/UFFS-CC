/*	UNIVERSIDADE FEDERAL DA FRONTEIRA SUL - UFFS
	CURSO: CIENCIA DA COMPUTAÇÃO, 4º FASE
	PROFESSOR: Doglas André Finco
	ALUNOS: Adriel Schmitz

	TRABALHO 2 - Grafos
	Implementação do algoritmo de busca de DIJKSTRA
	Dica de compilação: g++ dijkstra.cpp -o dijkstra -Wall
	Executar: ./dijkstra <entrada.in
*/
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

#define INF 112345678
#define TAM 30

typedef pair<int, int> tii; //tii.second() = distancias || tii.first() = vertice anterior

void preenche_matriz(int grafo[][TAM], int n, tii distancia[]);
void dijkstra(int grafo[][TAM], tii dist[], int u, int n);
void backtracking(tii distancia[], int i, int j);
void distancias(tii distancia[], int n);

int main(void){
	int n, grafo[TAM][TAM];
	tii distancia[TAM]; // vetor de distancia e vértice anterior
	system("clear");
	scanf("%d", &n);
	preenche_matriz(grafo, n, distancia);
	dijkstra(grafo, distancia, 0, n); //parametro 0 indicando o vértice de início
	return 0;
}

void preenche_matriz(int grafo[TAM][TAM], int n, tii distancia[TAM]){
	int i, j;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++)
			scanf("%d", &grafo[i][j]);
		
		distancia[i].second = INF; // seta todas as distancias pra infinito
	}
}

void backtracking(tii distancia[TAM], int i, int j){
    if(i)
    	backtracking(distancia, distancia[i].first, j);
    
    printf("%c%s", i == 20 ? 'z' : 'a'+i, i == j ? "\n" : " -> ");
}

void distancias(tii distancia[TAM], int n){
	int i;
	printf("Distancias em relação ao vértice [a]: \n");
	printf("|    Vértice\t|    Distância\t|\n");
	for(i=0; i<n; i++){
		printf("|\t%c\t|\t%d\t|", i==20 ? 'a'+25 : 'a'+i, distancia[i].second);
		printf("\n");
	}
}

void dijkstra(int grafo[][TAM], tii distancia[], int atual, int n){
    priority_queue< tii, vector<tii>, greater<tii> > fila;
	distancia[atual].second = 0; // distancia do vértice
    distancia[atual].first = atual; // u recebe ele mesmo como vértice anterior
    int dist;

    fila.push(tii(0, atual));//insiro o vértice inicial na fila com distancia 0
    while(!fila.empty()){
        atual = fila.top().second;
        dist = fila.top().first;
		fila.pop();
		if(dist > distancia[atual].second) 
			continue;
        for(int i=0; i<n; i++){
            if(grafo[atual][i] > 0 && distancia[i].second > (distancia[atual].second + grafo[atual][i])){
                distancia[i].second = distancia[atual].second + grafo[atual][i]; //
                distancia[i].first = atual;
                fila.push(tii(distancia[i].second, i));
            }
        }
    }
    printf("\n\t******* DIJKSTRA *******");
    printf("\nMenor caminho: ");
	backtracking(distancia, n-1, n-1);
	printf("Distancia = [%d]\n", distancia[n-1].second);
	distancias(distancia, n);
}