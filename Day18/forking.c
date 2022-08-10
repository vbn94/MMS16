#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
    int pid = fork();
    if (-1 == pid){
        perror("fork");
        return EXIT_FAILURE;
    }
    if (0 == pid){
        // child
        printf("Hello, I'm child! My PID is %d. My PPID = %d\n", getpid(), getppid());

    } else {
        // parent
        sleep(1);
        printf("Hello, I'm parent! My PID is %d. My PPID = %d\n", getpid(), getppid());
        
        wait(NULL);
    }

    // child and parent
    sleep(10);
    return 0;
}