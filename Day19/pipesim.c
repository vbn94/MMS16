#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    int fd[2];
    if (pipe(fd) == -1) {
        return EXIT_FAILURE;
    }
    
    int pid1 = fork();
    if (pid1 < 0) {
        return EXIT_FAILURE;
    }
    
    if (pid1 == 0) {
        // Child process 1 (ping)
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        execlp("ping", "ping", "-c", "2", "google.com", NULL);
    }
    
    int pid2 = fork();
    if (pid2 < 0) {
        return EXIT_FAILURE;
    }
    
    if (pid2 == 0) {
        // Child process 2 (grep)
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);
        execlp("grep", "grep", "rtt", NULL);
    }
    
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    
    return EXIT_SUCCESS;
}