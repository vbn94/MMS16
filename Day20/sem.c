#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>


sem_t sem;

void *routine(void* args){
    //sleep(3);
    printf("Hello from thread!\n");
    sem_post(&sem);
}

int main(){
    sem_init(&sem, 0, 0);
    pthread_t th;
    if (pthread_create(&th, NULL, routine, NULL)){
        perror("phtread_create");
        exit(EXIT_FAILURE);
    }
    
    sem_wait(&sem);
    printf("Hello from main!\n");

    if (pthread_join(th, NULL)){
        perror("phtread_create");
        exit(EXIT_FAILURE);
    }
    sem_destroy(&sem);
    return EXIT_SUCCESS;
}