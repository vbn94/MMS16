#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>

#define THR 10

pthread_mutex_t mux;
sem_t sem;


int num = 0;

void *routine(void* args){
    usleep(1000);
    for (int i = 0; i < 1000; i++){
        //pthread_mutex_lock(&mux);
        sem_wait(&sem);
        num++; // critical section
        sem_post(&sem);
        //pthread_mutex_unlock(&mux);
    }
}

int main(){
    pthread_t th[THR];
    sem_init(&sem, 0, 1); // binary semaphore
    pthread_mutex_init(&mux, NULL);
    for (int j = 0; j < THR; j++){
                // th+j == &th[j]
                if (pthread_create(th+j, NULL, routine, NULL)){
                    perror("phtread_create");
                    exit(EXIT_FAILURE);
                }
            }        
    for (int j = 0; j < THR; j++){
                if (pthread_join(th[j], NULL)){
                    perror("phtread_join");
                    exit(EXIT_FAILURE);
                }
    }
    pthread_mutex_destroy(&mux);
    sem_destroy(&sem);
    printf("Num = %d\n", num);      
    return EXIT_SUCCESS;
}