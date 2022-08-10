#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    //FILE* fnames = fopen("myfile", "r");
    //int sym;
    /*// fseek(fnames, 2L, SEEK_SET);
    // fseek(fnames, -5L, SEEK_END);
    fgetc(fnames);
    fgetc(fnames);
    fseek(fnames, -1L, SEEK_CUR);
    while ((sym = fgetc(fnames)) != EOF){
        putchar(sym);
    }*/
    /*printf("%ld\n", ftell(fnames));
    fseek(fnames, 0L, SEEK_END);
    printf("%ld\n", ftell(fnames));
    fseek(fnames, 5L, SEEK_SET);
    printf("%ld\n", ftell(fnames));
    fclose(fnames);*/

    int fd = open("myfile", O_RDONLY);
    lseek(fd, 2L, SEEK_SET);
    char sym;
    while (read(fd, &sym, 1))
    {
        write(STDOUT_FILENO, &sym, 1);
    }
    close(fd);
    return 0;
}