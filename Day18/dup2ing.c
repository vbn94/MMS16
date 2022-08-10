#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    int fd1 = open("output", O_WRONLY | O_CREAT | O_TRUNC, 0777);
    dup2(fd1, STDOUT_FILENO);
    printf("Hello MMS C Camp!\n");
    close(fd1);
    return 0;
}