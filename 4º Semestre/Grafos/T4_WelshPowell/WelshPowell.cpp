/*	UNIVERSIDADE FEDERAL DA FRONTEIRA SUL - UFFS
	CIENCIA DA COMPUTAÇÃO, 4º FASE
	PROFESSOR: DOGLAS ANDRÉ FINCO
	ALUNOS: ADRIEL SCHMITZ
	TRABALHO 4 - GRAFOS
	Implementação dos algoritmos de coloração de Welsh & Powell
	Compilar = g++ WelshPowell.cpp -Wall
	Executar = ./a.out <entrada.in
*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define TAM 30

typedef pair<int, int> ii;
typedef pair<int, ii> tii;

int buscaProximoVertice(tii grau_cor[], int vetor[], int cor, int n);
void fechaVertices(int G[][TAM], int vetor[], int atual, int n);
void preencheMatriz_ordenaGrau(int grafo[][TAM], tii grau_cor[], int n);
void WelshPowell(int G[][TAM], tii grau_cor[], int n);
void imprime_WelshPowell(tii grau_cor[], int n);
bool abreVertices(int vet[], int n);

int main(int argc, char const *argv[]){
	system("clear");
	int grafo[TAM][TAM], n;
	tii grau_cor[TAM];
	scanf("%d", &n);
	preencheMatriz_ordenaGrau(grafo, grau_cor, n);
	WelshPowell(grafo, grau_cor, n);
	return 0;
}
void preencheMatriz_ordenaGrau(int grafo[][TAM], tii grau_cor[], int n){
	priority_queue< tii, vector<tii> > fila;
	int i, j;
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++)
			scanf("%d", &grafo[i][j]);
		grau_cor[i].first = 0; //Seta todos os graus pra 0
	}
	for(i=0; i<n; i++){
		for(j=0; j<n; j++)
			if(grafo[i][j] > 0) 
				grau_cor[i].first++; //Atualiza o grau de cada vértice
		fila.push(tii((int)grau_cor[i].first, ii(i, -1))); //Passa o grau como parametro pra fila de prioridade
	}
	i = 0;
	while(!fila.empty()){ //Passa pra estrutura ordenado pelo grau
		grau_cor[i] = fila.top();
		i++; fila.pop();
	}
}
void WelshPowell(int G[][TAM], tii grau_cor[], int n){
	int vetor[n]; memset(vetor, -1, sizeof(vetor));
	int atual, cor = 1;
	do{
		while(1){
			atual = buscaProximoVertice(grau_cor, vetor, cor, n);
			if(atual != -1) 
				fechaVertices(G, vetor, atual, n);
			else break;
		}
		cor++;
	}while(abreVertices(vetor, n));//enquanto a função retornar true, é porquê tem vértices a serem pintados
	
	imprime_WelshPowell(grau_cor, n);
}
int buscaProximoVertice(tii grau_cor[], int vetor[], int cor, int n){
	int i, v, u;
	for(i=0; i<n; i++){
		v = grau_cor[i].second.first;
		u = grau_cor[i].second.second; 
		if(u == -1 && vetor[v] == -1){//Testa se tem um grau aberto
			grau_cor[i].second.second = vetor[v] =  cor; // seta a cor do vertice atual
			return v; //retorna o próximo vertice atual
		}
	}
	return -1;
}
void fechaVertices(int G[][TAM], int vetor[], int atual, int n){
	for(int j=0; j<n; j++)
		if(G[atual][j] == 1 && vetor[j] == -1) // fecha temporariamente os vizinhos do atual
			vetor[j] = 0;
}
bool abreVertices(int vet[], int n){
	int i, flag = 0;
	for(i=0; i<n; i++){
		if(vet[i] == 0) vet[i] = -1;//Se tem algum em 0, é porquê ele foi fechado temporariamente, abre novamente
		if(vet[i] == -1) flag = 1;//Verifica se tem algum pra ser o próximo ainda
	}
	if(flag) return true;
	else return false;
}
void imprime_WelshPowell(tii grau_cor[], int n){
	printf("_________________________________________________\n");
	printf("|     Vértice\t|\tGrau\t|\tCor\t|\n");
	printf("|_______________|_______________|_______________|\n");
	for(int i=0; i<n; i++)
		printf("|\t%c\t|\t%d\t|\t%d\t|\n", grau_cor[i].second.first+65, grau_cor[i].first, grau_cor[i].second.second);
	printf("|_______________|_______________|_______________|\n");
}