#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX	200

int pilha[MAX];
int topo;

void pilha_construir(){
	topo = -1; // topo nao contém nada;
}
int pilha_vazia(){
	if(topo==-1){
		return 1;
	}else{
		return 0;
	}
}
int pilha_cheia(){
	if (topo == MAX-1){
		return 1;
	}else{
		return 0;
	}
}
int pilha_empilhar(int valor){ // push = inserir;
	if(pilha_cheia()){
		return 0;
	}else{
		pilha [topo] = valor;
		topo++;
		return 1;
	}
}
int pilha_desempilhar(int valor){ // pop = retirar;
	if( pilha_vazia() ){
		return 0;
	}else{
		valor = pilha[topo];
		topo--;
		return 1;
	}
}
int pilha_tamanho(){
	return topo+1;
}
int pilha_consulta(int valor){
	if ( !pilha_vazia() ){
		return 0;
	}else{
		valor = pilha[topo];
		return 1;
	}
}
int main(){
	int entrada;
	printf("Informe valores!\n");
	pilha_construir();
	while( scanf("%d", &entrada) == 1 ){ // scaneia até chegar um caracter diferente de um numero inteiro;
		
		pilha_empilhar(entrada);	
	}

	printf("último item da pilha: %d\n", valor);
	printf("Qtd de itens: %d\n", pilha_tamanho(valor) );
	printf("A nova pilha tem: %d numeros\n", pilha_desempilhar(valor) );
	pilha_consulta(valor);
	printf("\nÚltimo item da pilha contém o Nº %d\n", valor);
	return 0;
}