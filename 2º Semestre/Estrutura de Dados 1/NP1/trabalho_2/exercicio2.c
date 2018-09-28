/* Altere o programa para armazenar uma estrutura 
em um vetor.!
typedef struct{	
	 char nome[50];	
	 char endereco[100];	
	 int matricula;	
} estudante;	*/
#include <stdio.h>
#include <stdlib.h>

typedef struct{	
	char nome[50];	
	char endereco[100];	
	int matricula;	
} estudante;

int main(){
	int i, n;
	estudante *vet;
	printf("Informe a quantidade que deseja alocar: ");
	scanf("%d", &n);
	vet = (estudante*)calloc(n, sizeof(estudante));
	for(i=0; i<n; i++){ // entrada de dados, de acordo com o valor alocado desejado;
		getchar();
		printf("Nome do %dº aluno: ", i+1);
		scanf(" %[^\n]", vet[i].nome); // armazena toda a entrada do teclado até o \n;
		printf("Endereço: ");
		getchar();
		scanf(" %[^\n]", vet[i].endereco);
		printf("Matrícula: ");
		scanf("%d", &vet[i].matricula);
		printf("\n");
	}
	printf("\n");
	printf("------ Aluno(s) que possui(em) cadastro(s) ------\n");
	for(i=0; i<n; i++){ // printagem do resultado alocado;
		printf("\nNome: %s\n", vet[i].nome);
		printf("Endereço: %s\n", vet[i].endereco);
		printf("Matrícula: %d\n", vet[i].matricula);
	}
	free(vet);// libera a memória alocada;
	
 return 0;
}
