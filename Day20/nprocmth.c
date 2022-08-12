#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <pthread.h>

#define PROC 2
#define THR 10

void *routine(void* args){
    printf("My PID = %d, Thread ID = %ld\n", getpid(), pthread_self());
}


int main(){
    for (int i = 0; i < PROC; i++){
        pid_t pid = fork();
        if (-1 == pid){
            perror("forking");
            return EXIT_FAILURE;
        }
        if (0 == pid){
            // child
            pthread_t th[THR];
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
            exit(EXIT_SUCCESS);
        }
    }
    for (int i = 0; i < PROC; i++){
        wait(NULL);
    }
    return EXIT_SUCCESS;
}