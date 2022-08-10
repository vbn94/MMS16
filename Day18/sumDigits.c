#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <time.h>

int digitsSum(int number){
    int sum = 0;
    while (number != 0){
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int main(int argc, char **argv){
    srand(time(NULL));
    for (int i = 1; i < argc; i++){
        pid_t pid = fork();
        if (-1 == pid){
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if (0 == pid){
            int num;
            sleep(rand() % 4);
            sscanf(argv[i], "%d", &num);
            printf("Sum digits of %d = %d\n", num, digitsSum(num));
            exit(EXIT_SUCCESS);
        }
    }
    for (int i = 1; i < argc; i++){
        wait(NULL);
    }
    return EXIT_SUCCESS;
}