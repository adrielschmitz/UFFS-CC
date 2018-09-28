#include <cstdio>
#include <cstring>

using namespace std; 

#define _8K 8192
#define MAX 61235

typedef struct{
	char a[_8K];
}pag;



int main(void){
	int i, b, fim = _8K;
	char in[MAX], s1[MAX], s2[MAX];
	fgets(in, MAX, stdin);
	pag a;

	sscanf(in, "%s %*s %s %*s %d", s1, s2, &b);
	void *p = &a.a;
	fim -= strlen(s1);

	for(i = 0; i < (int)strlen(s1); i++){
		*(char*)(p + fim + i) = s1[i];
	}
	fim -= strlen(s2);
	for(i = 0; i < (int)strlen(s2); i++){
		*(char*)(p + fim + i) = s2[i];
	}
	fim -= sizeof(int)+1;
	*(int*)(p + fim) = b;
	for(i = 0; i < _8K; i++){
		if(i >= fim && i <= fim+sizeof(int)){
			printf("%d", *(int*)(p + fim));
			i += 4;
		}
		else
			printf("%c",a.a[i]);
	}
	printf("\n");
	return 0;
}