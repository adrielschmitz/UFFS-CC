/*	-- Adriel Schmitz, Sistemas Operacionais
	-- compilação: gcc B.c -lpthread -Wall -o exB
	-- exec: ./exB 			*/
#include <semaphore.h> 
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define MAX 10
#define N 3 // number of threads

sem_t semaforo;

int x = 0;

void *thread_counter(void *t_id);

int main(void){
	pthread_t tids[N];
    int i;

    sem_init(&semaforo, 0, 1); // inicializa o semáforo com valor 1 indicando que é pra uso com threads
    for(i=0; i<N; i++){ // create of the threads
		int *j = malloc(sizeof(int));
		*j = i;
		pthread_create(&tids[i], NULL, thread_counter, (void *)j);
	}
	for(i=0; i<N; i++) // wait for the end of the threads
		pthread_join(tids[i], NULL);

	return 0;
}

void *thread_counter(void *t_id){
	int id, flag = 0;

	while(1){
		if(x > MAX) break;
		id = *((int*) t_id);
		if(flag < N){
			if(id == flag){
				sem_wait(&semaforo); // DOWN operation
				printf("Thread id = %d global = %d\n", id, ++x);
				sem_post(&semaforo); // UP operation
				sleep(1);
			}
			flag++;
		}else
			flag = 0;
	}
	free((int*)t_id);
	pthread_exit(NULL);
}