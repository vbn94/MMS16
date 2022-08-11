#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>

int main(){

    int fd[2];
    if (pipe(fd) == -1){ // fd[0] -> read, fd[1] -> write
        perror("pipe");
        return EXIT_FAILURE;
    }

    pid_t pid = fork();

    if (-1 == pid){
        perror("fork");
        return EXIT_FAILURE;
    }

    if (0 == pid){
        // child
        close(fd[0]);
        char *str = "Hello, MMS C Camp 16! 12345";
        unsigned len = strlen(str) + 1;
        write(fd[1], &len, sizeof(len));  
        write(fd[1], str, strlen(str) + 1);       
        close(fd[1]);
    } else {
        // parent
        close(fd[1]);
        char buff[200];
        unsigned len;
        read(fd[0], &len, sizeof(len));
        read(fd[0], buff, len);
        close(fd[0]);
        wait(NULL);
        printf("String from child: %s\n", buff);
    }

    return EXIT_SUCCESS;
}