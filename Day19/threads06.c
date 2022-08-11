#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>


sem_t parking; 

void* routine(void* args){
    int n = *(int*)args;
    free(args);
    printf("[%d] Waiting for parking....\n", n);
    sem_wait(&parking);
    printf("[%d] Car is in parking...\n", n);
    sleep(rand() % 10);
    printf("[%d] Out of parking...\n", n);
    sem_post(&parking);
}

int main(){
    pthread_t th[COUNT];
    sem_init(&parking, 0, 3);
    for (int i = 0; i < COUNT; i++){
        int* number = malloc(sizeof(int));
        *number = i;
        if (pthread_create(th + i, NULL, routine, number)){
            perror("create");
            return EXIT_FAILURE;
        }
    }
    for (int i = 0; i < COUNT; i++){
        if (pthread_join(th[i], NULL)){
            perror("join");
            return EXIT_FAILURE;
        }
    }
    sem_destroy(&parking);
    return EXIT_SUCCESS;
}