#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define N			5
#define LEFT		(i+N-1)%N
#define RIGHT		(i+1)%N 
#define THINKING 	0
#define HUNGRY 		1
#define EATING		2

void think(int i);
void eat(int i);
void *philosopher(void *i);
void put_forks(int i);
void take_forks(int i);
void test(int i);

int state[N];
sem_t s[N];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main(void){
	int i;
	pthread_t tids[N];

	for(i = 0; i < N; i++)
		sem_init(&s[i], 1, 0);

	for(i=0; i<N; i++) {
		int *j = malloc(sizeof(int));
		*j = i;
		pthread_create(&tids[i], NULL, philosopher, (void *)j);
	}

	for(i=0; i<N; i++) {
		pthread_join(tids[i], NULL);
		printf("Thread id %ld returned\n", tids[i]);
	}
	return 0;
}

void think(int i){
	printf("%d's thinking\n", i);
	sleep(rand()%N+1);
	return;
}

void eat(int i){
	printf("%d's eating\n", i);
	sleep(rand()%N+1);
	return;
}

void test(int i){
	if (state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {
		state[i] = EATING;
		sem_post(&s[i]);
	}else
		printf("%d waiting\n", i);
	return;
}
void take_forks(int i){
	pthread_mutex_lock(&mutex);
	state[i] = HUNGRY;
	test(i);
	pthread_mutex_unlock(&mutex);
	sem_wait(&s[i]);
}
void put_forks(int i){
	pthread_mutex_lock(&mutex);
	state[i] = THINKING;
	test(LEFT);
	test(RIGHT);
	pthread_mutex_unlock(&mutex);
}
void *philosopher(void *i){
	int id = *((int *) i);
	free((int *)i);

	while(1){
		think(id);
		take_forks(id);
		eat(id);
		put_forks(id);
	}

	pthread_exit(NULL);
}
