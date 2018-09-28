#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define num 2

typedef struct Aluno{
	char nome[30];
	float nota[3];
	float media;
}_aluno;

int main(){
	_aluno alunos[num]; // declarando alunos e relacionando a struct aluno;
	int i,j;
	for(i=1; i<=100; i++){
		printf("Informe a nota do %dº aluno\n", i);
		printf("Nome: ");
		getchar(); // limpando o buffer do teclado;
		scanf("%[^\n]s", alunos[i].nome); // lendo caracteres do teclado, limitando de a-z ou de A-Z;
		alunos[i].media=0;
		for(j=1; j<=3; j++){
			printf("Nota da %dº avaliação\n", j);
			scanf("%f", &alunos[i].nota[j]);
			alunos[i].media = alunos[i].media+alunos[i].nota[j];
		}
	 alunos[i].media = alunos[i].media/3;
	}

	printf("\nMedias dos alunos\n");
	for (i=1; i<=num; i++)
		printf("Nome: %s - Media: %.1f\n", alunos[i].nome, alunos[i].media);
	
	return 0;
}