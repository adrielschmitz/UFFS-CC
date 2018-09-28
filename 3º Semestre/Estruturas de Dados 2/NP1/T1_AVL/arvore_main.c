/* 	UNIVERSIDADE FEDERAL DA PRONTEIRA SUL - UFFS
	3º FASE DO CURSO DE CIÊNCIA DA COMPUTAÇÃO
	Trabalho I da desciplina de ESTRUTURA DE DADOS II - 2017
	Implementação da Arvore AVL com valores positivos em C Ansi
	Alunos: ADRIEL SCHMITZ e MAICON BRANDÃO
	Professor: Doglas André Finco
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "declaracoes_funcoes.h"

int main(void){
	TpArvore *arvore = inicializa();
	int escolha, flag = 1, chave;
	while(flag){
		system("clear");
		menu();
		while(scanf("%d", &escolha) != 1) 
			getchar();
		switch(escolha){
			case 0:
				flag = 0;
				break;
			case 1:
				printf("\nValor da chave: ");
				while((scanf("%d", &chave)) != 1);
				arvore->raiz = inserir_nodo(arvore->raiz, chave);
				printf("Pressione ENTER para continuar...\n");	
				getchar();
				getchar();
				break;
			case 2:
			    Imprime_arvore(arvore->raiz);
			    printf("Pressione ENTER para continuar...\n");	
			    getchar();
			    getchar();
				break;
			case 3:
				printf("\tAltura: %d\n", Busca_altura(arvore->raiz));
				printf("Pressione ENTER para continuar...\n");	
				getchar();
			    getchar();
				break;
			default: 
				printf("**ERROR** OPÇÃO INVÁLIDA!\n");
		}	
	}
  return 0;
}