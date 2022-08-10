#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

int main(){
    pid_t pid1 = fork();
    if (-1 == pid1){
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (0 == pid1){
        // 2
        printf("Process 2\n");
    } else {
        pid_t pid2 = fork();
        if (0 == pid2){
            // 3
            pid_t pid3 = fork();
            if (0 == pid3){
                // 4 
                printf("Process 4\n");
            } else {
                pid_t pid4 = fork();
                if (pid4 == 0){
                    // 5
                    printf("Process 5\n");
                } else {
                    // 3
                    printf("Process 3\n");
                    wait(NULL);
                    wait(NULL);
                }
            }
        } else { 
            // 1
            printf("Process 1\n");
            wait(NULL);
            wait(NULL);
        }
    }
    return EXIT_SUCCESS;
}