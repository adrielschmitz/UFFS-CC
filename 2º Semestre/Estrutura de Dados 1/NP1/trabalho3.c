#include <stdio.h>
#include <string.h>

#define MAX 300

typedef struct { // criando e renomeando uma struct do tipo pilha;
	char p[MAX];
	int topo;
}pilha;

pilha frase; // define frase como uma variavel do tipo pilha só que global;

void inverte(char tmp[]){ // função pra inversao da palavra;
	int inicio=0, fim, i;
	frase.topo=0;
	while(tmp[inicio] != '\n'){ // while para quando chegar o no \n;
		if(inicio){
			inicio++;
		}
		for(i=inicio; i<strlen(tmp); i++){ // strlen verifica e retorna o tamanho da string;
			if(tmp[i] == ' ' || tmp[i] == '\n'){ // se na posição i da string tiver um espaço ou um \n, fim recebe o i e para o for;
				fim = i;
				break;
			}
		}
		for(i=fim-1; i>=inicio; i--){ 
			frase.p[frase.topo] = tmp[i];
			frase.topo++;
		}
		if(tmp[fim] == ' '){ // se na string tiver um espaço, ele vai pro topo e mantém no mesmo lugar;
			frase.p[frase.topo] = ' ';
			frase.topo++;
		}
		inicio = fim;
	}
}

int main(void){
	char aux[MAX];
	//scanf(" %[^\n]", aux);
	fgets(aux, MAX, stdin); // captura a string do teclado;
	inverte(aux); // passa aux como parâmentro pra função inverte;
	printf("%s\n", frase.p); // 
	return 0;
}