#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

int main(){
    int numbers[] = { 1, 1, 1, 2, 2, 2 };
    int len = sizeof(numbers) / sizeof(*numbers);
    int sum = 0;
    int fd[2];
    if (pipe(fd) == -1){
        perror("pipe");
        return EXIT_FAILURE;
    }
    pid_t pid = fork();
    if (0 == pid){
        // child
        close(fd[0]);
        for (int i = 0; i < len / 2; i++){
            sum += numbers[i];
        }
        printf("Sum1 = %d\n", sum);
        write(fd[1], &sum, sizeof(sum));
        close(fd[1]);

    } else {
        // parent
        close(fd[1]);
        for (int i = len / 2; i < len; i++){
            sum += numbers[i];
        }
        printf("Sum2 = %d\n", sum);
        wait(NULL);
        int sumChild;
        read(fd[0], &sumChild, sizeof(sumChild));
        int total = sum + sumChild;
        printf("Total = %d\n", total);
        close(fd[0]);
    }
    return EXIT_SUCCESS;
}