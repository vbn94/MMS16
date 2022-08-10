#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    int fd1 = open("myfile", O_RDONLY);
    int fd2 = dup(fd1);
    char sym;
    while (read(fd1, &sym, 1))
    {
        write(STDOUT_FILENO, &sym, 1);
    }
    lseek(fd1, 0L, SEEK_SET);
    while (read(fd2, &sym, 1))
    {
        write(STDOUT_FILENO, &sym, 1);
    }
    close(fd1);
    close(fd2);
    return 0;
}