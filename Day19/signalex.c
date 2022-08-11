#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>
#include <signal.h>

void getHint(int sig){
    printf("[Hint]: Firts multiplication, then addition!\n");
}

int main(){
    pid_t pid = fork();
    if (-1 == pid){
        perror("fork");
        return EXIT_FAILURE;
    }

    if (0 == pid){
        // child
        sleep(5);
        kill(getppid(), SIGUSR1);
    } else {
        // parent
        struct sigaction sa;
        sa.sa_handler = getHint;
        sa.sa_flags = SA_RESTART;
        sigaction(SIGUSR1, &sa, NULL);
        int num;
        printf("5 + 2 * 6 = ?\n");
        scanf("%d", &num);
        if (18 == num){
            printf("Bravo!\n");
        } else {
            printf("Error!\n");
        }
        kill(pid ,SIGTERM);
        wait(NULL);
    }

    return EXIT_SUCCESS;
}