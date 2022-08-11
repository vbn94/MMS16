#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>


int main(){
    char cmd[200];
    while (scanf("%s", cmd) != EOF){
        if (!strcmp(cmd, "ls")){
            pid_t pid = fork();
            if (0 == pid){
                // child
                execlp("ls", "ls", NULL);
            }
        }
    }
    return EXIT_SUCCESS;
}