/* 	UNIVERSIDADE FEDERAL DA PRONTEIRA SUL - UFFS
	3º FASE DO CURSO DE CIÊNCIA DA COMPUTAÇÃO
	Trabalho II da desciplina de ESTRUTURA DE DADOS II - 2017
	Implementação da Arvore RUBRO NEGRA com valores positivos em C Ansi
	Alunos: ADRIEL SCHMITZ e MAICON BRANDÃO
	Professor: Doglas André Finco
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "declaracoes_funcoes_rubro_negra.h"

int main(){
	TpArvore *arvore=(TpArvore*)malloc(sizeof(TpArvore));
	int escolha, flag = 1, flag_chave_invalida, chave;
	arvore = inicializa();
	
	while(flag){
		menu();
		while(scanf("%d", &escolha) != 1){
			getchar();
			printf("Opção inválida.\n");
		}
		switch(escolha){
			case 0:
				flag = 0;
				break;
			case 1:
		        do{
					printf("\nInsira somente números positivos.\n");
					printf("Valor da chave: ");
					while((scanf("%d", &chave) != 1)){
						getchar();
						printf("Insira somente números positivos.\n");
					}
					chave >= 0 ? (flag_chave_invalida = 0) : (flag_chave_invalida = 1);
				}while(flag_chave_invalida);

				arvore->raiz = insere_nodo(arvore->raiz, chave);

				printf("\tPressione ENTER para continuar...\n");	
				getchar();
				getchar();
				break;
			case 2:
			    printf("\n");
				imprime_arvore(arvore->raiz);
			    printf("\tPressione ENTER para continuar...\n");	
			    getchar();
			    getchar();
				break;
			default:
				printf("\tOpção Invalida\n\n");
				printf("\tPressione ENTER para continuar...\n");	
				getchar();
				getchar();
				break;
		}	
	}
  	return 0;
}