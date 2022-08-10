#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

int main(){
    for (int i = 0; i < N; i++){
        pid_t pid = fork();
        if (0 == pid){
            printf("Hello from process %d!\n", i);
            exit(EXIT_SUCCESS);
        }
    }

    for(int i = 0; i < N; i++){
        wait(NULL);
    }
    return EXIT_SUCCESS;
}