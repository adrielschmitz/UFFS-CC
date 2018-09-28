#include <stdio.h>
#include <string.h>
#include <algorithm>

using nomespace std;
#define MAX 122	

int main(){
	int N, i, maior;
	
	char str[MAX] [MAX];
	while (scanf ("%d, &N, N")) {
	  	maior = 0;
		for(i=0; i<N; i++) {
			scanf("%s", str[1]);
			strlen(str[1])
			maior = max((int)strlen(str[1], maior));
		}
	}
	for (i=0; i<N; i++){
		tamanho = strlen (str[1]);
		espaços = maior - tamanho;
		while (espaços --) {
			printf (" ");	
			printf ("*%s\n", maior, str[1]);
		}
	}
  return 0;
}


















	}