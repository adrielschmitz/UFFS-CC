#include <stdio.h>
#include <stdlib.h>

#define N 10000

int main(void){
	int id[N], sz[N], i, j, p, q;
	
	for(i=0; i<N; i++) 
		id[i] = i;
	while(scanf("%d %d\n", &p, &q) != EOF){
		for(i = p; i != id[i]; i = id[i]) 
			id[i] = id[id[i]];
		for(j = q; j != id[j]; j = id[j]) 
			id[j] = id[id[j]];
		if(i == j) continue;
		/*if(sz[i] < sz[j]){
			id[i] = j;
			sz[j] += sz[i];
		}else{
			id[j] = i; 
			sz[i] += sz[j];
		}*/
		printf(" %d -> %d\n", p, q);
	}
	return 0;
}