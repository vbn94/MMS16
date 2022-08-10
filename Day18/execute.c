#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

int main(){
    printf("Hello\n");
    pid_t pid = fork();
    if (0 == pid){
        execlp("ls", "ls", "-l", "-a", "execute.c", NULL);
    } else {
        wait(NULL);
        printf("Bye bye!\n");
    }
    return EXIT_SUCCESS;
}