#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 1200	
int main(){

	int N, i, maior, tamanho, espacos, fim = 0;
	char str [MAX][MAX];

	while (scanf ("%d",&N), N) {
		if (fim)
		printf ("\n");
		fim=1;

		maior =0;
		for(i=0;i<N;i++){
			scanf ("%s", str[i]);
			maior = max( (int)strlen(str[i]) ,maior);
		}
		for (i=0;i<N;i++){
			tamanho = strlen(str[i]);
			espacos = maior - tamanho;

			while (espacos--){
				printf (" "); 	
			}
		 printf ("%s\n", str[i]);
		}
	}	

		return 0;
}
