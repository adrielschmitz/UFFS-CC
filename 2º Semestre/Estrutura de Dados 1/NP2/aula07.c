#include <stdio.h>

double max(double v[], int n){
	int i;
	double maior=0;
	for(i=0; i<n;i++){
		if(v[i]>maior){
			maior = v[i];
		}
	}
	return maior;
}

int main(){
	double s[100];
	int i, n;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%lf", &s[i]);
	}
	printf("O maior eh = %.1lf\n", max(s, n));

}