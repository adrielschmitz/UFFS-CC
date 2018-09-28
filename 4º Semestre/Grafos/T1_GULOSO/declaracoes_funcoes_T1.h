#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 112345678
#define V_INICIAL 1

int kadu_inc2(int grafo[][9], int visitados[], int v_atual, int v_final);
int kadu_adj2(int grafo[][7], int visitados[], int v_atual, int v_final);
int kadu_inc(int grafo[][8], int visitados[], int v_atual);
int kadu_adj(int grafo[][5], int visitados[], int v_atual);
void menu_matrizes();
void menu();

#include "funcoes_T1.c"