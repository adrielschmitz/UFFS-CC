#include <cstdio>#include <cstring>using namespace std;#define _8k 8192#define MAX 123typedef struct{    char a[_8k];}pag;int main(void){    char entrada[MAX], word[MAX][MAX];    memset(word, -1, sizeof(word));    pag pagina;    int i;    while( strcmp(word[0],"create") || strcmp(word[1], "table") ){        printf("Crie uma tabela inserindo os dados corretamente!!\n");        fgets(entrada, MAX, stdin);         sscanf(entrada, "%s %s", word[0], word[1]);    }    for(i = 0; i < (int)strlen(entrada); i++){        if(entrada[i] == '(' || entrada[i] == ')' || entrada[i] == '[' || entrada[i] == ']' || entrada[i] == ',')            entrada[i] = ' ';        else if(entrada[i] == '\n')            entrada[i] = '\0';    }    void* p = &pagina.a;    *(int*)p = _8k - 4;    sscanf(entrada+12, "%s", word[0]);    for(i=0; i<(int)strlen(word[0]); i++)        *(char*)(p+(_8k - *(int*)p) + i) = word[i];     return 0;}