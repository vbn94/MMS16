#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

// #define COUNT 1

pthread_mutex_t mux;

unsigned long long count = 0;

void *routine(void* arg){
    sleep(5);
    for (int i = 0; i < 10000; i++){
        pthread_mutex_lock(&mux);
        count++;   // critical section
        pthread_mutex_unlock(&mux);
    }
}


int main(){
    pthread_t th[COUNT];
    pthread_mutex_init(&mux, NULL);
    for (int i = 0; i < COUNT; i++){
        if (pthread_create(th + i, NULL, routine, NULL)){
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
    pthread_mutex_destroy(&mux);
    printf("Count = %llu\n", count);
    return EXIT_SUCCESS;
}