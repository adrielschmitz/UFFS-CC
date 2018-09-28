/*	UNIVERSIDADE FEDERAL DA FRONTEIRA SUL - UFFS
	CURSO: CIENCIA DA COMPUTAÇÃO, 4 FASE
	PROFESSOR: DOGLAS ANDRÉ FINCO
	TRABALHO 1 - GRAFOS
	ALUNOS: ADRIEL SCHMITZ e LEONARDO WERLANG
*/
#include "declaracoes_funcoes_T1.h"

int main(void){
	int escolha, flag_1, flag_2, problema, flag=1, visitados[7];
	int adj[5][5] = {{INF, 30, -15, INF, 20}, {-30, INF, -10, 50, INF}, { 15, 10, INF, 5, -10}, {INF, 50, -5, INF, -30}, {-20, INF, 10, 30, INF} };
	int inc[5][8] = {{ 30, INF, INF, 20, -15, INF, INF, INF}, {-30, 50, INF, INF, INF, -10, INF, INF}, {INF, INF, INF, INF, 15, 10, 5, -10}, {INF, 50, -30, INF, INF, INF, -5, INF}, {INF, INF, 30, -20, INF, INF, INF, 10}};
	int adj2[7][7] ={{INF, 2, INF, 6, 12, INF, INF}, { -2, INF, 1, INF, INF, 5, INF}, {INF, -1, INF, INF, INF, INF, 40}, { -6, INF, INF, INF, INF, 4, INF}, {-12, INF, INF, INF, INF, INF, 30}, {INF, -5, INF, -4, INF, INF, 8}, {-40, INF, INF, INF, -30, -8, INF}};
	int inc2[7][9] ={{2, 6, 12, INF, INF, INF, INF, INF, INF}, {-2, INF, INF, 1, 5, INF, INF, INF, INF}, {INF, INF, INF, -1, INF, INF, 40, INF, INF}, {INF, -6, INF, INF, INF, 4, INF, INF, INF}, {INF, INF, -12, INF, INF, INF, INF, INF, 30}, {INF, INF, INF, INF, -5, -4, INF, 8, INF}, {INF, INF, INF, INF, INF, INF, -40, -8, -30} };

	do{
		system("clear");
		menu();
		while(scanf("%d", &problema) != 1) getchar();
		switch(problema){
			case 0:
				flag = 0;
				break;
			case 1:
				flag_1 = 1;
				while(flag_1){
					menu_matrizes();
					while(scanf("%d", &escolha) != 1) getchar();
					switch(escolha){
						case 0:
							flag_1 = 0;
							break;
						case 1:
					 		memset(visitados, 0, sizeof(visitados));
					 		printf("\n");
							printf("%d\n", kadu_adj(adj, visitados, V_INICIAL-1));
							printf("\nPressione ENTER para continuar...");
							getchar();
							getchar();
							break;
					 	case 2:
							memset(visitados, 0, sizeof(visitados));
							printf("\n");
							printf("%d\n", kadu_inc(inc, visitados, V_INICIAL-1));
							printf("\nPressione ENTER para continuar...");
							getchar();
							getchar();
							break;
					 	default:
					 		break;
					}
				}
				break;
			case 2:
				flag_2 = 1;
				do{
					menu_matrizes();
					while( scanf("%d", &escolha) != 1 ) getchar();
					switch(escolha){
						case 0:
							flag_2 = 0;
							break;
						case 1:
							memset(visitados, 0, sizeof(visitados));
							printf("\n");
							printf("%d\n", kadu_adj2(adj2, visitados, (V_INICIAL-1), 7));
							printf("\nPressione ENTER para continuar...");
							getchar();
							getchar();
							break;
						case 2:
							memset(visitados, 0, sizeof(visitados));
							printf("\n");
							printf("%d\n", kadu_inc2(inc2, visitados, (V_INICIAL-1), 7));
							printf("\nPressione ENTER para continuar...");
							getchar();
							getchar();
							break;
						default:
							break;
					}
				}while(flag_2);
				break;
			default:
				printf("\t**Informe apenas 0, 1 ou 2!**\n");
				break;
		}
	}while(flag);
 	return 0;
}
