#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>
#include <signal.h>


int main(){
    pid_t pid = fork();
    if (-1 == pid){
        perror("fork");
        return EXIT_FAILURE;
    }

    if (0 == pid){
        // child
       exit(EXIT_SUCCESS);
    } else {
        // parent
        int ret
        waitpid(pid, &ret, 0);
        printf("Exit status- %d\n", WEXITSTATUS(ret));
    }

    return EXIT_SUCCESS;
}