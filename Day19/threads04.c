#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>


void *routine(void* arg){
    sleep(1);
    int val = *(int*)arg;
    printf("Number = %d\n", val);
    free(arg);
}


int main(){
    pthread_t th[COUNT];
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
   
    return EXIT_SUCCESS;
}