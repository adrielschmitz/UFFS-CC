#include <stdio.h>
#include <stdlib.h>

void cmp(int *a, const void *b){
	if(a > b){
		return 1;
	}else if(a < b){
		return -1;
	}
 	return 0;

}

int main(){
	int i, vet[5] = {0, 3, 6, 2, 11};
	qsort(vet, 5, sizeof(int), cmp);
	for(i=0; i<5; i++){
		printf("%d ", vet[i]);
	}

	return 0;
}
