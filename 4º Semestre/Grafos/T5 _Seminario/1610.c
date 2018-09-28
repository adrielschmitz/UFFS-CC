#include <stdlib.h>
#include <stdio.h>

#define N 112345

void Union(int id[], int p, int q);
int find(int id[], int p);

int main(void){
	int i, t, n, m, a, b, flag, id[N];

	scanf("%d", &t);
	while(t--){
		flag = 0;
		scanf("%d %d", &n, &m);
		for(i=0; i<N; i++)
			id[i] = i;
		while(m--){
			scanf("%d %d", &a, &b);
			if(find(id, a) != find(id, b))
				Union(id, a, b);
			else
				flag = 1;
		}
		flag == 1 ? printf("SIM\n") : printf("NAO\n");
	}
	return 0;
}
int find(int id[], int p){
	if(id[p] == p) return p;
	return id[p] = find(id, id[p]);
}
void Union(int id[], int p, int q){
	p = find(id, p); 
	q = find(id, q);
	id[p] = q;
}