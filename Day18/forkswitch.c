#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

int main(){
    pid_t pid = fork();
    switch (pid){
        case -1:
            perror("fork");
            exit(EXIT_FAILURE);
        case 0:
            // child
            for (int i = 0; i < 10; i++){
                printf("Hello, I'm child!\n");
                sleep(1);
            }
            break;
        default:
           // parent
           for (int i = 0; i < 10; i++){
                printf("Hello, I'm parent!\n");
                sleep(1);
            }
           wait(NULL);
           break;
    }
    return EXIT_SUCCESS;
}