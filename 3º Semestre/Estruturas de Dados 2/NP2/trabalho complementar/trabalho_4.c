/*	UNIVERSIDADE FEDERAL DA FRONTEIRA SUL - UFFS
	CURSO: CiêNCIA DA COMPUTAÇÃO, 3º FASE
	PROFESSOR: DOGLAS ANDRÉ FINCO
	TRABALHO 4 – ESTRUTURA DE DADOS II
	ALUNO: ADRIEL SCHMITZ
*/
#include <stdio.h>
#include <stdlib.h>

#define  MAX 20 //tamanho da string pro nome do produto

typedef struct _produto{
	int codigo;
	char nome[MAX];
	double preco;
}TpProduto;

void inserir_produtos(FILE *arquivo);
void imprimir(FILE *arquivo);
void menu();

int main(void){

	FILE *arquivo = fopen("ListaProdutos.txt", "w");
	if(arquivo == NULL){
		printf("\t**ERROR** Nao foi possivel criar arquivo de armazenamento!\n");
		getchar();
		return 0;
	}

	int escolha, flag = 1;

	while(flag){
		menu();
		while(scanf("%d", &escolha) != 1){
			getchar();
			printf("\tOpcao invalida.\n");
		}
		switch(escolha){
			case 0:
				flag = 0;
				break;
			case 1:
				system("clear");
				inserir_produtos(arquivo);
				printf("\n\tPressione ENTER para continuar...");	
				getchar();
				getchar();
				break;
			case 2:
				system("clear");
				imprimir(arquivo);
			    printf("\n\tPressione ENTER para continuar...");	
			    getchar();
			    getchar();
				break;
			default:
				printf("\tInforme 0, 1 ou 2 somente!\n\n");
				printf("\n\tPressione ENTER para continuar...");	
				getchar();
				getchar();
				break;
		}	
	}
  return 0;
}

void inserir_produtos(FILE *arquivo){
	TpProduto lista_produtos;

	arquivo = fopen("ListaProdutos.txt", "a");
	printf("\tInforme o codigo do produto = ");
	while( scanf("%d", &lista_produtos.codigo) != 1 )
		getchar();
	
	getchar();
	printf("\tInforme o nome do produto = ");
	scanf("%[^\n]", lista_produtos.nome);
	printf("\tInforme o preco do produto = ");
	scanf("%lf", &lista_produtos.preco);
	fprintf(arquivo, "Id = %d\tNome = %s\tPreco = R$ %.2lf\n", lista_produtos.codigo, lista_produtos.nome, lista_produtos.preco);

	fclose(arquivo);
}

void imprimir(FILE *arquivo){
	if( (arquivo = fopen("ListaProdutos.txt", "r")) == NULL ){
		printf("Nao foi possivel abrir o arquivo!\n");
		getchar();
		exit(0);
	}

	char aux;

	printf("Lista: \n");
	while( feof(arquivo) == 0 ){
		aux = fgetc(arquivo);
		putchar(aux);
	}
	rewind(arquivo);

	fclose(arquivo);
}

void menu(){
	system("clear");
	printf("\tEscolha uma opcao:\n");
	printf("\t[1] Inserir novo produto\n");
	printf("\t[2] Listar produtos cadastrados\n");
	printf("\t[0] Sair\n");
	printf("\tOpcao -> ");
}
