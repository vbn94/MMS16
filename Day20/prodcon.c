// Producer-consumer problem
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

#define THR 10
#define BUFF_SIZE 10

pthread_mutex_t mux;
sem_t emptySem;
sem_t fullSem;

int buff[BUFF_SIZE];
int top = 0;


void *consumer(void* arg){
    while (1){
        sem_wait(&fullSem);
        int x;
        pthread_mutex_lock(&mux);
        x = buff[--top];  // critical section
        pthread_mutex_unlock(&mux);
        printf("Value = %d\n", x);
        sem_post(&emptySem);
    }
}


void *producer(void* arg){
    while (1){
        sleep(1);
        sem_wait(&emptySem);
        int x = 1 + rand() % 100;
        pthread_mutex_lock(&mux);
        buff[top++] = x;  // // critical section
        pthread_mutex_unlock(&mux);
        sem_post(&fullSem);
    }
}

int main(){
    srand(time(NULL));
    pthread_mutex_init(&mux, NULL);
    sem_init(&emptySem, 0, BUFF_SIZE);
    sem_init(&fullSem, 0, 0);
    pthread_t th[THR];
    for (int i = 0; i < THR; i++){
        if (i % 2 == 0){
            // producer 
            if (pthread_create(th + i, NULL, producer, NULL)){
                perror("join");
                return EXIT_FAILURE;
            }
        } else {
            // consumer
            if (pthread_create(th + i, NULL, consumer, NULL)){
                perror("join");
                return EXIT_FAILURE;
            }
        }
    }

    for (int i = 0; i < THR; i++){
        if (pthread_join(th[i], NULL)){
            perror("join");
            return EXIT_FAILURE;
        }
    }
    pthread_mutex_destroy(&mux);
    sem_destroy(&emptySem);
    sem_destroy(&fullSem);
    return EXIT_SUCCESS;
}