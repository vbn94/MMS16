#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>
#include <signal.h>

void handler(int sig){
    printf("\nBye bye. Have a nice day!\n");

    exit(EXIT_SUCCESS);
}

int main(){
    struct sigaction sa;
    sa.sa_handler = handler;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGINT, &sa, NULL);
    
    while (1);
    return EXIT_SUCCESS;
}