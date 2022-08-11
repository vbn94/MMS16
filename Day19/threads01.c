#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>


void sleep_ms(unsigned ms){
    usleep(ms * 1000);
}


void *routine1(void* arg){
    int n = 5;
    while (--n){
        printf("MMS C Camp\n");
        sleep_ms(1000);
    }
}

void *routine2(void* arg){
    int n = 8;
    while (--n){
        printf("Hello world!\n");
        sleep_ms(500);
    }
}

int main(){
    pthread_t th1, th2;
    if(pthread_create(&th1, NULL, routine1, NULL)){
        perror("thread create");
        return EXIT_FAILURE;

    }
    
    if(pthread_create(&th2, NULL, routine2, NULL)){
        perror("thread create");
        return EXIT_FAILURE;

    }

    if(pthread_join(th1, NULL)){
        perror("join");
        return EXIT_FAILURE;

    }
    if(pthread_join(th2, NULL)){
        perror("join");
        return EXIT_FAILURE;
    }
    printf("Bye bye!\n");
    return EXIT_SUCCESS;
}