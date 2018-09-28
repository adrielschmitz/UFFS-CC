#include <stdio.h>
#define n 15

int main(){
    char nome[n];
    int i;
    setbuf(stdin, NULL);
    scanf("%[^\n]s", nome);
    for(i=1; i<=n; i++){
    	printf("%c", nome[n-i]);
    }
    printf("\n");
}
