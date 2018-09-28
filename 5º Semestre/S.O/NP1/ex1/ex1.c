/*
	Adriel Schmitz, Sistemas Operacionais
	compilação: gcc ex1.c -lpthread -Wall -o exercicio1
	exec: ./exercicio1	
*/

#include <pthread.h>
#include <unistd.h> 
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void *thread1(void *data);
void *thread2(void *data);

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER, mutex2 = PTHREAD_MUTEX_INITIALIZER;
pthread_t Thread1, Thread2;

int main(void) {

    pthread_create(&Thread1, NULL, thread1, NULL);
    pthread_create(&Thread2, NULL, thread2, NULL);

    //now join them
    pthread_join(Thread1, NULL);
    printf("Thread idth1 main %ld returned\n", Thread1);
    pthread_join(Thread2, NULL);
    printf("Thread idth2 main %ld returned\n", Thread2);

    return 0;
}

void *thread1(void *data){
    unsigned long i;

    if(pthread_mutex_trylock(&mutex1) == 0){
        printf("Thread ID A: %ld got mutex1.\n", pthread_self());
    	sleep(rand()%5);
        for(i=0; i< 10000000; ++i); // just for wasting some time
        if(pthread_mutex_trylock(&mutex2) == 0){
            printf("Thread ID B: %ld got mutex2.\n", pthread_self());          
        	sleep(rand()%5);
            for(i=0; i< 10000000; ++i); // just for wasting some time
            pthread_mutex_unlock(&mutex2);   
        }else
    		printf("\nThread ID C: %ld did not get mutex2.\n", pthread_self()); pthread_mutex_unlock(&mutex2);
   		pthread_mutex_unlock(&mutex1);
    }
    else 
    	printf("\nThread IDth1 else:%ld did not get mutex1.\n", pthread_self()); pthread_mutex_unlock(&mutex1);
  	pthread_exit(NULL);
}

void *thread2(void *data){
    unsigned long i;

    if(pthread_mutex_trylock(&mutex2) == 0){
        printf("Thread ID D: %ld got mutex2.\n", pthread_self());
    	sleep(rand()%5);
        for(i=0; i< 10000000; ++i); // just for wasting some time
        if(pthread_mutex_trylock(&mutex1) == 0){
        	printf("Thread ID E 2: %ld got mutex1.\n", pthread_self());          
        	sleep(rand()%5);
            for(i=0; i< 10000000; ++i); // just for wasting some time
            pthread_mutex_unlock(&mutex1);   
        }
        else
        	printf("\nThread ID F: %ld did not get mutex1.\n", pthread_self()); pthread_mutex_unlock(&mutex1);
        pthread_mutex_unlock(&mutex2);
    }else
     	printf("\nThread IDth2 else: %ld did not get mutex2.\n", pthread_self()); pthread_mutex_unlock(&mutex2);
  	pthread_exit(NULL);
}

/*
	RESPOSTA: Na linha 32, 35, 51 e 54 us-ase ao 
*/