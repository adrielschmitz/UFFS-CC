#include <stdio.h>
#include <queue>

using namespace std;

typedef pair<int, int>ii;
typedef pair<int, ii>tii;

int find(int id[], int p){
	if(id[p] == p) return p;
	return id[p] = find(id, id[p]);
}
void Union(int id[], int p, int q){
	p = find(id, p);
	q = find(id, q);
	id[q] = p;
}
void Kruskal(int n, int m){
	priority_queue< tii, vector<tii>, greater<tii> > fila;
	int pai[n+1], peso, u, v, p, q, i, cont = 0;

	while(scanf("%d %d %d", &u, &v, &peso) != EOF)
		fila.push(tii(peso, ii(u, v)));

	for(i=0; i<n; i++) 
		pai[i] = i;

	while(!fila.empty()){
		p = (int)fila.top().second.first;
		q = (int)fila.top().second.second;
		if(find(pai, p) != find(pai, q)){
			Union(pai, p, q);
			cont += (int)fila.top().first;
		}
		fila.pop();
	}
	printf("%d\n", cont);
}

int main(int argc, char const *argv[]){
	int m, n;
	scanf("%d %d", &m, &n);
	Kruskal(n, m);
	return 0;
}
