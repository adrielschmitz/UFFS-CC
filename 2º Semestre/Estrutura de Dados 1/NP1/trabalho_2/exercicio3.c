/* 3) Altere o programa do exercício 1, de forma que receba números inteiros do usuário indefinidamente. 
O programa finaliza quando o usuário entrar com uma letra.!
a) Aloque, inicialmente, memória para 5 inteiros;!
b) Caso o usuário entrar com mais inteiros, faça a realocação, alocando espaço para mais 5 inteiros e assim sucessivamente; */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int *j, n=5, i=0, realoca=0, cont=0;
	j = (int*)calloc(n, sizeof(int));
	char vet[11];

	printf("Informe valores! Para parar informe uma letra\n");
	while( scanf("%s", vet) != 1){ //testa se a entrada é um número inteiro;
		
		cont++;
		realoca++;
		if(realoca==5){ // se realoca for igual a 5, significa que ja armazenou 5 inteiros e precis de mais;
			n+=5;
			int *jn = realloc (j, n*sizeof(int)); // criado um ponteiro que recebe um novo valor realocado (mais 5 inteiros);
				if(jn){ // testa se foi realocado;
					j = jn; // caso realocado, fazer o j receber o novo valor realocado;
					printf("Memória realocada!\n");
				}else{
					printf("Nao foi possível realocar mais memória!\n");
				}
		}
	/* NOTA: nao sei mais como fazer a partir daqui professor, 
	nao quero copiar dos outros ou algo assim, eu fiz até onde eu sabia, testei
	li os slides mas nao entendi o problema direito, se possível queria que o senhor
	fizesse no quadro e tirasse mais dúvidas; */
	}
	return 0;
}
