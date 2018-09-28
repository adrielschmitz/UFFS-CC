#include <stdio.h>

int main(){
	int pascal[100][100], j , i, n, tam;
	printf("Digite a quantidade de linhas: ");
	scanf("%d", &n);
	tam = n;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			pascal[i][j] = 0;
		}
	}
	pascal[0][0] = 1;
	for(i=1; i<n; i++){
		for(j=0; j<n; j++){
			if(j == 0){
				pascal[i][j] = pascal[i-1][j];
			}else{
				pascal[i][j] = pascal[i-1][j]+pascal[i-1][j-1];
			}
		}
	}
	for(i=0; i<n; i++){
		for(j=0; j<=i; j++){
			if(j==0){
				printf("%*d ",tam, pascal[i][j]);
			}else{
				printf("%d ", pascal[i][j]);
			}
		}
		tam--;
		printf("\n");
	}
}