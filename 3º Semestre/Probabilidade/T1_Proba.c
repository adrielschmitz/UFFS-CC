#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Cn_x = (n!)/x!*(n-x)!
//P(x=)= Cn,x * p^x * q^(n-x)

// COMPILAÇÃO = gcc T1_Proba.c -o T1_Proba -Wall -lm

double fatorial(int valor);
double tabelaA(int n, int x_a, double p_a);
void tabelaB(int n, int x, double p);
void menu();

int main(void){
	system("clear");
	int opcao, n, x, flag=1, flag_n, flag_x;
	double p = 0, proba_tab_A;

	while(flag){
		menu();
		while( scanf("%d", &opcao) != 1 ){
			printf("\n\t\tINFORME APENAS NÚMEROS!");
			printf("\n\t\t Opção -> ");
			getchar();
		}	
		switch(opcao){
			case 0:
				flag = 0;
				break;
			case 1:
				system("clear");
				flag_n = 1;
				flag_x = 1;
				printf("\n\t\t----------- INDIVIDUAL -----------");
				while(flag_n){
					printf("\n\t\tQual o valor de n? -> ");
					scanf("%d", &n);
					if(n <= 25)
						flag_n = 0;
					else
						printf("\t\t**ERROR** INFORME UM 'N' MENOR QUE 26!");
				}
				while(flag_x){
					printf("\n\t\tQual o valor de x? -> ");
					scanf("%d", &x);
					if(x <= n)
						flag_x = 0;
					else
						printf("\t\t**ERROR** INFORME UM 'X' MENOR QUE OU IGUAL AO N!");
				}
				printf("\t\tQual o valor de p? (ex: 0.25) -> ");
				scanf("%lf", &p);
				proba_tab_A = tabelaA(n, x, p);
				printf("\n\t\tP(x = %d) = %.4lf\n", x, proba_tab_A);
				printf("\t\t--------------------------------\n\n");
				break;
			case 2:
				system("clear");
				flag_n = 1;
				flag_x = 1;
				printf("\n\t\t----------- ACUMULADA -------------");
				while(flag_n){
					printf("\n\t\tQual o valor de n? -> ");
					scanf("%d", &n);
					if(n <= 25)
						flag_n = 0;
					else
						printf("\t\t**ERROR** INFORME UM 'N' MENOR QUE 26!");
				}
				while(flag_x){
					printf("\n\t\tQual o valor de x? -> ");
					scanf("%d", &x);
					if(x <= n)
						flag_x = 0;
					else
						printf("\t\t**ERROR** INFORME UM 'X' MENOR QUE OU IGUAL AO N!");
				}
				printf("\t\tQual o valor de p? (ex: 0.25) -> ");
				scanf("%lf", &p);
				tabelaB(n, x, p);
				break;
			default:
				printf("\n\t\tOPÇÃO INVÁLIDA!\n");
		}
	}
	return 0;
}

double fatorial(int valor){
	double fat = 1;
	for( int i = 2; i <= valor; i++ )
    	fat *= i;
	
  return fat;
}

double tabelaA(int n, int x_a, double p_a){
	double Cn_x, proba, q = 1-p_a;

	Cn_x = (fatorial(n)) / ((fatorial(x_a)) * (fatorial(n-x_a)));

	proba = Cn_x * pow(p_a, x_a) * pow(q, (n-x_a));

	return proba;
}

void tabelaB(int n, int x, double p){
	int i;
	double resultado = 0;
	for(i = 0; i <= x; i++)
		resultado += tabelaA(n, i, p);

 	printf("\n\t\tP(x = %d) = %.4lf\n", x, resultado);
	printf("\t\t--------------------------------\n\n");
}

void menu(){
	printf("\n\t\t|----------------------------------------|");
    printf("\n\t\t|     TABELA DE DISTRIBUIÇÃO BINOMIAL    |");
    printf("\n\t\t|----------------------------------------|");
    printf("\n\t\t|[1] TABELA INDIVIDUAL                   |");
	printf("\n\t\t|[2] TABELA ACUMULADA                    |");
	printf("\n\t\t|[0] SAIR                                |");
	printf("\n\t\t|----------------------------------------|");
	printf("\n\t\t Opção -> ");
}