#include <stdio.h>

int main(){
	typedef struct{
		int dia, mes, ano;
	} data;

	printf("Tem alocado no sistema %d bytes para a variável data\n", sizeof(data));

	return 0;
}
/* função sizeof serve para mostrar quantos de espaço foi alocado em uma determinada variável,
por exemplo: A variável data, é uma struct, e dentro dela tem mais 3 variáveis do tipo inteiro;
cada variável do tipo inteiro é alocado pra ela 4 bytes, entao a variável data contem 12 bytes 
de memória reservado pra ela! */
