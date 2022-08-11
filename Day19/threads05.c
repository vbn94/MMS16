#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>


void *routine(void* arg){
    int* num = malloc(sizeof(int)); 
    *num = rand() % 100;
    return num;
}


int main(){
    srand(time(NULL));
    pthread_t th[COUNT];
    for (int i = 0; i < COUNT; i++){
        if (pthread_create(th + i, NULL, routine, NULL)){
            perror("create");
            return EXIT_FAILURE;
        }
    }
    for (int i = 0; i < COUNT; i++){
        int *ptrValue;
        if (pthread_join(th[i], (void**)&ptrValue)){
            perror("join");
            return EXIT_FAILURE;
        }
        printf("Value = %d\n", *ptrValue);
        free(ptrValue);
    }
   
    return EXIT_SUCCESS;
}