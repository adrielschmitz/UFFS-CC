#include <stdio.h>
#include <stdlib.h>

int main(){
  int *valores , *tmp;
  int i = 0, j = 5, valor;
  
  valores = (int*)malloc(sizeof(int)*5);

  while(scanf("%d",&valor) == 1 ){ 
    tmp = valores+i;
    *tmp = valor;
    i++;
    if(i > (j-1)){
      j += 5;
      valores = (int*) realloc(valores, j * sizeof(int));
    }
  }
  j = i;
  
  for(i = 0; i < j; i++){
    tmp = valores+i;
    printf("[%d]%d\n",(i+1),*tmp);
  }
  free(valores);
  
  return 0;
}