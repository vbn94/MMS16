#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>
#include <signal.h>

void handler(int sig){
    printf("%d\n", rand() % 100);
}

int main(){
    srand(time(NULL));
    struct sigaction sa;
    sa.sa_handler = handler;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGUSR1, &sa, NULL);
    printf("My PID is %d\n", getpid());
    while (1);
    return EXIT_SUCCESS;
}