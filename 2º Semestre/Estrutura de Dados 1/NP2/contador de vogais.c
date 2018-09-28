#include <stdio.h>
#include <string.h>

int contavogal(char[]){
	int i, cont=0, tamanho;
	tamanho=strlen(s);
	for(i=0; i<tamanho; i++){
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
			cont++;
	}
	return cont;
}

int main(){
	char str[100];
	int n;
	printf("Informe uma palavra: ");
	gets(str);

	n = contavogal(str);
	printf("O numero de vogais desta string eh = %d\n", n);
	
	return 0;
}