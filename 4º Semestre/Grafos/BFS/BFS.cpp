/*	UNIVERSIDADE FEDERAL DA FRONTEIRA SUL - UFFS
	CURSO: CIENCIA DA COMPUTAÇÃO, 4º FASE
	PROFESSOR: Doglas André Finco
	ALUNOS: Adriel Schmitz

	TRABALHO 2 - Grafos
	Implementação dos algoritmos de buscas BFS
	Dica de compilação: g++ BFS.cpp -o bfs -Wall
	Executar: ./bfs < entrada.in
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
void BFS(int grafo[][TAM], tii distancia[], int u, int n);
void backtracking(tii distancia[], int i, int j);
void distancias(tii distancia[], int n);

int main(void){
	int n, grafo[TAM][TAM];
	tii distancia[TAM]; // vetor de distancia e vértice anterior
	system("clear");
	scanf("%d", &n);
	preenche_matriz(grafo, n, distancia);
	BFS(grafo, distancia, 0, n);//parametro 0 indicando o vértice de início
	return 0;
}

void preenche_matriz(int grafo[TAM][TAM], int n, tii distancia[TAM]){
	int i, j;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			scanf("%d", &grafo[i][j]);
		}
		distancia[i].second = INF; // seta todas as distancias pra infinito
	}
}

void backtracking(tii distancia[TAM], int i, int j){
    if(i){
    	backtracking(distancia, distancia[i].first, j);
    }
    printf("%c%s", i == 20 ? 'z' : 'a'+i, i == j ? "\n" : " -> ");
}

void distancias(tii distancia[TAM], int n){
	int cont=0, i;
	printf("Distancias em relação ao vértice 'a': \n");
	printf("|    Vértice\t|    Distância\t|\n");
	for(i=0; i<n; i++, cont = 1){
		while(cont--){
			printf("|\t%c\t|\t%d\t|", i==20 ? 'a'+25 : 'a'+i, distancia[i].second);
			printf("\n");
		}
	}
}

void BFS(int grafo[][TAM], tii distancia[TAM], int u, int n){
    int fila[TAM], inicio=0, fim=0, v;
    fila[0] = u;
    distancia[u].second = 0;
    distancia[u].first = u;
    while(inicio <= fim){
        u = fila[inicio];
        inicio++;
        for(v=0; v<n; v++){
            if(grafo[u][v] > 0 && distancia[v].second > (distancia[u].second+1)){
                distancia[v].second = distancia[u].second+1;
                distancia[v].first = u;
                fim++;
                fila[fim] = v;
            }
        }
    }
    printf("\t********** BFS *********");
    printf("\nMenor caminho: ");
	backtracking(distancia, n-1, n-1);
	printf("Distancia = [%d]\n", distancia[n-1].second);
	distancias(distancia, n);
}
