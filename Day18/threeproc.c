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
        // child
        pid_t pid2 = fork();
        if (-1 == pid2){
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if (pid2 == 0){
            printf("PID: %d PPID: %d\n", getpid(), getppid());
        } else {
            printf("PID: %d PPID: %d\n", getpid(), getppid());
            wait(NULL);
        }
    } else {
        // parent
        printf("PID: %d PPID: %d\n", getpid(), getppid());
        wait(NULL);
    }
    return EXIT_SUCCESS;
}