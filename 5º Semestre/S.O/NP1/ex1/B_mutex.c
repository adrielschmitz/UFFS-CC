/*	
	-- Adriel Schmitz, Sistemas Operacionais
	-- compilação: gcc B.c -lpthread -Wall -o exB
	-- exec: ./exB
B) Desenvolver um programa multithread com as seguintes funcionalidades:
- A partir da thread principal criar N threads;
- Cada thread executa, basicamente, a mesma tarefa que consiste em incrementar uma 
variável global inicializada com valor zero (0); no entanto, a cada rodada envolvendo 
todas as threads, cada thread incrementa a variável global uma única vez. Além disso, 
a alternância entre as threads dá-se sempre em ordem crescente de identificadores. 
Assumir identificadores das threads incrementais iniciando-se a primeira thread com 
ID = 0. Exemplo: assumindo que existem 3 threads (ids 0, 1 e 2), ter-se-á a seguinte 
apresentação de incremento da variável global:

- thread 0: global = 1;
- thead 1: global =2;
-thread 2: global =3;
-thread 0: global = 4;
-thread 1: global =5;
...
O incremento da variável global finaliza quando atingir um valor pré-estabelecido MAX 
(definido também pelo usuário).
*/

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void *thread_counter(void *thread_ID);

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // mutex criado e inicializado

#define MAX 10 

int X = 0;

int main(void){
	int i, N;

	printf("N of the threads: ");
	scanf("%d", &N);

	pthread_t tids[N]; // create a thread vector

	for(i=0; i<N; i++){ // create of the threads
		int *j = malloc(sizeof(int));
		*j = i;
		pthread_create(&tids[i], NULL, thread_counter, (void *)j);
	}

	for(i=0; i<N; i++) // wait for the end of the threads
		pthread_join(tids[i], NULL);

	pthread_mutex_destroy(&mutex);
	
	return 0;
}

void *thread_counter(void *thread_ID){ //receives the each thread identification
	int id, flag = 0;

	id = *((int*) thread_ID);
	free((int*) thread_ID);

	while(X < MAX){
		if(flag < 3){// order threads
			//if(id == flag)
				if(id == flag && pthread_mutex_trylock(&mutex) == 0){
					printf("Thread id = %d global = %d\n", id, ++X);
					pthread_mutex_unlock(&mutex);
					sleep(1);
				}
			flag++;
		}else
			flag = 0;
	}
	pthread_exit(NULL);
}