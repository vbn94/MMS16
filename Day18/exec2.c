#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

int main(){
    printf("Hello\n");
    pid_t pid1 = fork();
    if (0 == pid1){
        execl("/usr/bin/ls", "ls", "-l", "-a", "execute.c", NULL);
        perror("exec error");
    } else {
        pid_t pid2 = fork();
        if (0 == pid2){
            char *arguments[] = { "ping", "www.google.com", "-c", "3", NULL };
            execvp("ping", arguments);
        } else {
            wait(NULL);
            wait(NULL);
            printf("Bye bye!\n");
        }
    }
    return EXIT_SUCCESS;
}