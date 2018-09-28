#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct _lista{
	int info, info_2, frequencia;
	struct _lista *prox;
}lista;

lista *insere_fim_freq(lista *l, int num, int freq);
lista *insere_fim(lista *l, int num);
lista *inicializa();
void df_sem_intervalo(lista *l);
void dados_isolados(lista *l);
void imprime_lista(lista *l);
void df_com_intervalo();
void imprime_menu();

int main(){
	lista *l;
	l = inicializa();
	int escolha, escolha_2, flag = 1, flag_2 = 1, freq;
	while(flag){
		imprime_menu();
		while(scanf("%d", &escolha) != 1){
			getchar();
			imprime_menu();
		}
		while(flag_2){
			if(escolha == 1){
				int numero;
				system("clear");
				printf("Informe os dados isolados separados por espaço:\n*[Digite uma letra para parar]\n");
				while(scanf("%d", &numero) == 1){
					l = insere_fim(l, numero);				
				}
				dados_isolados(l);
				printf("\nDeseja fazer outra operação?\nSim[1] | Não[2]: ");
				while(scanf("%d", &escolha_2) != 1) getchar();
				if(escolha_2 == 1){
					free(l);
					flag = 1;
					break;
				}else if(escolha_2 == 2){
					flag = 0;
					break;
				}else{
					system("clear");
					printf("Opção inválida!\n");
					flag = 1;
					break;
				}
			}else if(escolha == 2){
				int numero;
				system("clear");
				printf("Insira os Dados[xi] e suas respectivas Frequências[fi].\n*[Digite uma letra para parar]\n");
				while(scanf("%d %d", &numero, &freq) == 2){
					l = insere_fim_freq(l, numero, freq);				
				}
				df_sem_intervalo(l);
				printf("\nDeseja fazer outra operação?\nSim[1] | Não[2]: ");
				while(scanf("%d", &escolha_2) != 1) getchar();
				if(escolha_2 == 1){
					free(l);
					flag = 1;
					break;
				}else if(escolha_2 == 2){
					flag = 0;
					break;
				}else{
					system("clear");
					printf("Opção inválida!\n");
					flag = 1;
					break;
				}
			}else if(escolha == 3){
				system("clear");
				df_com_intervalo();
				printf("\nDeseja fazer outra operação?\nSim[1] | Não[2]: ");
				while(scanf("%d", &escolha_2) != 1) getchar();
				if(escolha_2 == 1){
					free(l);
					flag = 1;
					break;
				}else if(escolha_2 == 2){
					flag = 0;
					break;
				}else{
					system("clear");
					printf("Opção inválida!\n");
					flag = 1;
					break;
				}
			}else{
				system("clear");
				printf("\tOpção inválida. Esolha a opção 1, 2 ou 3.\n");					
				flag = 1;
				break;
			}
		}		
	}
	system("clear");
	return 0;
}

lista *inicializa(){
	return NULL;
}

void imprime_menu(){
	system("clear");
	printf(" _______________________________________\n");
	printf("|                                       |\n");
	printf("|   1 - Dados isolados                  |\n");
	printf("|   2 - D.F. sem intervalos de classe   |\n");
	printf("|   3 - D.F. com intervalos de classe   |\n");
	printf("|_______________________________________|\n");
	printf("Escolha o tipo de dado que deseja inserir: ");
}

lista *insere_fim(lista *l, int num){
	lista *aux_l = l;
	lista *novo = (lista*)malloc(sizeof(lista));
	if(l == NULL){
		novo->info = num;
		novo->prox = NULL;
		return novo;
	}
	while(aux_l->prox != NULL){
		aux_l = aux_l->prox;
	}
	aux_l->prox = novo;
	novo->info = num;
	novo->prox = NULL;
	return l;
}

lista *insere_fim_freq(lista *l, int num, int freq){
	lista *aux_l = l;
	lista *novo = (lista*)malloc(sizeof(lista));
	if(l == NULL){
		novo->info = num;
		novo->frequencia = freq;
		novo->prox = NULL;
		return novo;
	}
	while(aux_l->prox != NULL){
		aux_l = aux_l->prox;
	}
	aux_l->prox = novo;
	novo->info = num;
	novo->frequencia = freq;
	novo->prox = NULL;
	return l;
}

void dados_isolados(lista *l){
	if(l == NULL){
		printf("Nenhum dado inserido.\n");
	}else{
		//parte da média----------------------
		lista *aux_l = l;
		double media, desvio, cv;
		media = desvio = cv = 0.0;
		int cont = 0;
		while(aux_l != NULL){
			media += aux_l->info;
			cont++;
			aux_l = aux_l->prox;
		}
		aux_l = l;
		media = media/cont;

		//desvio padrão e c.v.----------------
		while(aux_l != NULL){
			desvio += (aux_l->info - media)*(aux_l->info - media);
			aux_l = aux_l->prox;
		}
		desvio /= cont;
		desvio = sqrt(desvio);
		cv = (desvio/media)*100;
		//fim da parte para s. e c.v.---------
		system("clear");
		printf("Dados digitados: \n");
		imprime_lista(l);
		printf("\nMedia[X] = %.2lf\nDesvio Padrao[S] = %.2lf\nCoeficiente de Variação[C.v] = %.2lf%%\n", media, desvio, cv);		
	}
}

void df_sem_intervalo(lista *l){
	lista *aux_l = l;
	double media = 0.0, s = 0.0, cv = 0.0;
	int f_total = 0;
	while(aux_l != NULL){
		media += aux_l->info * aux_l->frequencia;
		f_total += aux_l->frequencia;
		aux_l = aux_l->prox;
	}
	media /= f_total;
	aux_l = l;
	while(aux_l != NULL){
		s += aux_l->frequencia * ((aux_l->info - media)*(aux_l->info - media));
		aux_l = aux_l->prox;
	}
	aux_l = l;
	s /= f_total;
	s = sqrt(s);
	cv = (s/media)*100;
	system("clear");
	printf("Dados || Frequência\n");
	while(aux_l != NULL){
		if(aux_l->info < 10){ 
			printf("|  %d  |", aux_l->info);
		}else if(aux_l->info>=10 && aux_l->info<100){
			printf("|  %d |", aux_l->info);
		}else{
			printf("| %d |", aux_l->info);
		}
		
		if(aux_l->frequencia < 10){
			printf("|  %d  |", aux_l->frequencia);
		}else if(aux_l->frequencia>=10 && aux_l->frequencia<100){
			printf("|  %d |", aux_l->frequencia);
		}else{
			printf("| %d |", aux_l->frequencia);
		}		
	  printf("\n");
	  aux_l = aux_l->prox;
	}
  printf("\nMedia[X] = %.2lf\nDesvio Padrao[S] = %.2lf\nCoeficiente de Variação[C.v] = %.2lf%%\n", media, s, cv);
}

void df_com_intervalo(){
	double media = 0, s = 0, cv = 0;
	int qtdados, primeiro_dado, ultimo_dado, i = 0, amplitude, ftotal = 0, flag_amplitde = 1;
	printf("Informe os dados com intervalos de classe.\nDigite o Primeiro e o Último dado: ");
	while(scanf("%d %d", &primeiro_dado, &ultimo_dado) != 2){
		getchar();
	}
	while(flag_amplitde){
		printf("Digite a amplitude das classes[h]: ");
		while(scanf("%d", &amplitude) !=1 ){
			getchar();
		}	
		amplitude < ((primeiro_dado+ultimo_dado)) ? flag_amplitde=0 : flag_amplitde++;
	}
	
	qtdados = (int)(ultimo_dado - primeiro_dado)/amplitude;
	int dados1[qtdados], dados2[qtdados], frequencia[qtdados], xi[qtdados];
	for(i=0; i<qtdados; i++){
		dados1[i] = primeiro_dado;
		primeiro_dado += amplitude;
		dados2[i] = primeiro_dado;
		if((primeiro_dado-amplitude) < 10){
			printf("Digite a frequência dos dados [%d]  |--- [%d]: ", (primeiro_dado-amplitude), primeiro_dado);	
		}else{
			printf("Digite a frequência dos dados [%d] |--- [%d]: ", (primeiro_dado-amplitude), primeiro_dado);
		}
		while(scanf("%d", &frequencia[i]) !=1){
			getchar();
		}
		xi[i] = ((dados2[i]+(dados1[i]))/2);
		media += xi[i]*frequencia[i];
		ftotal += frequencia[i];
	}
	media /= ftotal;
	for(i=0; i<qtdados; i++){
		s += ((xi[i] - media)*(xi[i] - media))*frequencia[i];
	}
	s /= ftotal;
	s = sqrt(s);
	cv = (s/media)*100;
	system("clear");
	printf("Media[x] = %.2lf\nDesvio Padrao[s] = %.2lf\nCoeficiente de Variação[C.v] = %.2lf%%\n", media, s, cv);
}

void imprime_lista(lista *l){
	if(l == NULL){
		printf("Nenhum elemento foi inserido.\n");
	}else{
		lista *aux_l = l;
		while(aux_l != NULL){
			printf("%d ", aux_l->info);
			aux_l = aux_l->prox;
		}		
	}
  printf("\n");
}