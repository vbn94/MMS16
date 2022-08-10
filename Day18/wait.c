#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

int main(){
    pid_t pid = fork();
    if (-1 == pid){
        perror("fork");
        return EXIT_FAILURE;
    }
    if (0 == pid){
        // child
        sleep(5);
        printf("Hello, I'm child!\n");
        sleep(2);
    } else {
        // parent
        printf("Hello, I'm parent!\n");
        wait(NULL);
        printf("Bye bye!\n");
    }
    printf("hello\n");
    return 0;
}