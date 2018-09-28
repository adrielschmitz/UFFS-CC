#include <stdio.h>

int main(){
	int n, i, aux,j;
	scanf("%d", &n);
	for(i=2; i<=n; i++){
	 	aux = 1;
		for(j=2; j<i; j++){
	 		if(i%j == 0){
	 			aux = 0;
	 				}
	 	}
	 	if(aux){
	 		printf("%d\n", i);
		}
	}


	return 0;
}