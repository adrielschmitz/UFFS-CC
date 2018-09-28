// Faça um programa que leia uma string e imprima esse nome inverso;
#include <stdio.h>
#include <string.h>

#define n 100

void inverte_nome(char nome[]){ // recebe uma string como parâmetro;
	int i, m;
	m = strlen(nome); // retorna o tamanho da string;
	printf("Nome inverso: ");
	for(i=1; i<=m; i++){
		printf("%c", nome[m-i]);
	}
	printf("\n");
}

int main(){
	char nome[n];
	setbuf(stdin, NULL); // limpa o buffer do teclado;
	printf("Informe o nome que deseja inverter: ");
	scanf("%[^\n]", nome); // armazena em nome a string até o enter informado do teclado;
	inverte_nome(nome); // chama a função inverte_nome e passa nome como parâmetro;

 return 0;
}
