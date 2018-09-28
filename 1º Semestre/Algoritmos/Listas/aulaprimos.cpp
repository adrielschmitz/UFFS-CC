#include <stdio.h>
#include <stdlib.h>
#define MAX 11234567

int primos[MAX], tp;

void crivo(){
	int i,j,flag;
	primos[tp=0] = 2;
	for(i=3 ; i<MAX; i++){
		for(flag=1, j=0; flag && j<=tp && primos[j]*primos[j]<=i; j++){
			 if(i%primos[j]==0) flag=0;
		}
		if(flag) 
			primos[++tp] = i;
	}
}
int fat(int N) {
	int i, ret;
	for (i = 0; N != 1; i++) {
		if(N % primos[1]==0) ret++;
		while(N%primos[i]==0) N/=primos[i];
	}
	return ret;
}
int main(void){
	int N;
	crivo();
	while(scanf("%d",&N), N) 
		printf("%d : %d\n", N, fat(N));
	

return 0;
}