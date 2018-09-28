#include <stdio.h>

int main(void){
	int x=1, *p1;
	double y=10.0, *p2;
	p1 = &x;
	p2 = &y;
		printf("O end de x eh = %p\n", p1); // %p para a printagem certa do alocamento de memória;
		printf("O end de y eh = %p\n", p2); 
}