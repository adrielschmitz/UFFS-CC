int kadu_adj(int grafo[][5], int visitados[], int v_atual){
	int menor = INF, existe_prox = -1, prox_v, j;
	visitados[v_atual] = 1;
	for(j=0; j<5; j++){ // linhas
		if(v_atual == j) continue;
		if(visitados[j] == 0 && grafo[v_atual][j] != INF && grafo[v_atual][j] > 0 && grafo[v_atual][j] < menor){
			menor = grafo[v_atual][j];
			existe_prox = prox_v = j;
		}
	}

    printf("(%d)%s", v_atual+1, existe_prox == -1 ? "" : " → ");

	if(existe_prox != -1) // verifica se existe um próximo vértice a ser visitado
		return menor + kadu_adj(grafo, visitados, prox_v); //retorna o valor da aresta que foi percorrida
	
	printf("\nCusto = ");
	return 0;
}
int kadu_inc(int grafo[][8], int visitados[], int v_atual){
	int menor = INF, existe_prox = -1, prox_v, j, k;

	visitados[v_atual] = 1;
	for(j=0; j<8; j++){ // colunas
		if(grafo[v_atual][j] > 0 && grafo[v_atual][j] != INF){
			for(k=0; k<5; k++){ // linhas
				if(v_atual == k) continue;
				if( grafo[v_atual][j] < menor && grafo[k][j] != INF && visitados[k] == 0){
					menor = grafo[v_atual][j];
					existe_prox = j;
					prox_v = k;
				}
			}
		}
	}
	if(existe_prox != -1){
		printf("(%d) → %c → ",v_atual+1, 'a' + existe_prox);
		return menor + kadu_inc(grafo, visitados, prox_v);
	}

	printf("(%d)\nCusto = ", v_atual+1);
	return 0;
}

//EXERCÍCIO 2 ----------------------------------------------------------------------------------------------------------------------

int kadu_adj2(int grafo[][7], int visitados[], int v_atual, int v_final){
	int menor = INF, existe_prox = -1, prox_v, j;
	visitados[v_atual] = 1;
	for(j=0; j<7; j++){
		if(v_atual == (v_final-1)) break;
		if(v_atual == j) continue;
		if(visitados[j] == 0 && grafo[v_atual][j] != INF && grafo[v_atual][j] > 0 && grafo[v_atual][j] < menor){
			menor = grafo[v_atual][j];
			existe_prox = prox_v = j;
		}
	}

    printf("(%d)%s", v_atual+1, existe_prox == -1 ? "" : " → ");

	if(existe_prox != -1)
		return menor + kadu_adj2(grafo, visitados, prox_v, v_final);
	
	printf("\nCusto = ");
	return 0;
}

int kadu_inc2(int grafo[][9], int visitados[], int v_atual, int v_final){
	int menor = INF, existe_prox = -1, prox_v, j, k;

	visitados[v_atual] = 1;
	for(j=0; j<7; j++){
		if(v_atual == (v_final-1)) break;
		if(grafo[v_atual][j] != INF && grafo[v_atual][j] > 0){
			for(k=0; k<9; k++){
				if(v_atual == k) continue;
				if(visitados[k] == 0 && grafo[k][j] != INF && grafo[v_atual][j] < menor){
					menor = grafo[v_atual][j];
					existe_prox = j;
					prox_v = k;
				}
			}
		}
	}
	if(existe_prox != -1){
		printf("(%d) → %c → ",v_atual+1, 'a' + existe_prox);
		return menor + kadu_inc2(grafo, visitados, prox_v, v_final);
	}

	printf("(%d)\nCusto = ", v_atual+1);
	return 0;
}
void menu_matrizes(){
	printf("\n\tQUAL MATRIZ DESEJA UTILIZAR?\n\t[1] Adjacencia\n\t[2] Incidencia\n\t[0] Voltar\n\t-> ");
}
void menu(){ 
	printf("\t  INFORME O GRAFO DESEJADO\n\t[1] Visita a todos os Vértices\n\t[2] Inicio ao Objetivo\n\t[0] Sair\n\t-> ");
}