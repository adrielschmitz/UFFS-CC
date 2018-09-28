/*	UNIVERSIDADE FEDERAL DA FRONTEIRA SUL - UFFS
	CURSO: CIENCIA DA COMPUTAÇÃO, 4º FASE
	PROFESSOR: Doglas André Finco
	ALUNOS: Adriel Schmitz, Leonardo Werlang

	TRABALHO 3 - Grafos
	Implementação dos algoritmos de Kruskal e de Prim
	Compilar = g++ KruskalPrim.cpp -o t3 -Wall
	Executar = ./t3 <entrada.in
*/
#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

#define TAM 30
#define INF 112345678

typedef pair<int, int>ii;
typedef pair<int, ii>tii;

void preenche_matriz(int grafo[][TAM], ii distancia[], int n);
void Prim(int grafo[][TAM], int atual, int n);
void imprime_prim(ii distancia[], int n);
void imprime_kruskal(tii arvore[], int n);
void Kruskal(tii arvore[], int n);
void Union(int id[], int p, int q);
int find(int id[], int p);

int main(void){
	int n, grafo[TAM][TAM];
	tii arvore[TAM];
	scanf("%d", &n);
	Prim(grafo, 0, n);
	scanf("%d", &n);
	Kruskal(arvore, n);
	return 0;
}

void preenche_matriz(int grafo[][TAM], ii distancia[], int n){
	int i, j;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++) 
			scanf("%d", &grafo[i][j]);
		distancia[i].first = -1; //vértice_pai
		distancia[i].second = INF; //distancia
	}
}

void Prim(int grafo[][TAM], int atual, int n){
	int i, arvore[TAM]; memset(arvore, 1, sizeof(arvore));
	priority_queue< ii, vector<ii>, greater<ii> > fila;
	ii distancia[n];

	preenche_matriz(grafo, distancia, n);
	distancia[atual].first = atual;
	distancia[atual].second = 0;
	fila.push(ii(0, atual));
	
	while(!fila.empty()){
		arvore[atual] = 0;
		atual = fila.top().second;
		fila.pop();
		for(i=0; i<n; i++){
			if(i == atual) 
				continue; //ignora todo o código que está a baixo
			if(arvore[i])
				if(grafo[atual][i] > 0 && grafo[atual][i] < distancia[i].second){
					distancia[i].second = grafo[atual][i];
					distancia[i].first = atual;
					fila.push(ii(distancia[i].second, i));
				}
		}
	}
	imprime_prim(distancia, n);
}

void imprime_prim(ii dist[], int n){
	int i, total=0;
	printf("------- PRIM -------\n");
	printf(" U  ->  V   : Custo\n");
	for(i=1; i<n; i++){
		printf("(%d) -> (%d)  : [%d]\n", i, dist[i].first, dist[i].second);
		total += dist[i].second;
	}
	printf("Custo = [%d]\n\n", total);
}

int find(int id[], int p){
	return id[p] == p ? p : id[p] = find(id, id[p]);
}

void Union(int id[], int p, int q){
	p = find(id, p);
	q = find(id, q);
	id[q] = p;
}

void Kruskal(tii arvore[], int n){
	priority_queue< tii, vector<tii>, greater<tii> > fila;
	int pai[n], peso, u, v, p, q, i, cont = 0;
	
	for(i=0; i<n; i++) pai[i] = i;
		
	while(scanf("%d %d %d", &peso, &u, &v) != EOF)//ordena as arestas conforme seus pesos, do menor pro maior
		fila.push(tii(peso, ii(u, v)));

	while(!fila.empty()){
		p = (int)fila.top().second.first;
		q = (int)fila.top().second.second;
		if(find(pai, p) != find(pai, q)){
			Union(pai, p, q);
			arvore[cont] = fila.top();
			cont++;
		}
		fila.pop();
	}
	imprime_kruskal(arvore, n-1);
}

void imprime_kruskal(tii arvore[], int n){
	int total = 0, i;
	printf("------ KRUSKAL ------\n");
	printf(" U  ->  V   : Custo\n");
	for(i=0; i<n; i++){
		printf("(%d) -> (%d)  : [%d]\n", arvore[i].second.first, arvore[i].second.second, arvore[i].first);
		total += (int)arvore[i].first;
	}
	printf("Custo = [%d]\n", total);
}