#include <stdio.h>  /* printf     */
#include <getopt.h> /* getopt API */
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    int n = 10;
    int opt;
    int fd_o = -1, fd_e = -1;
    while ((opt = getopt(argc, argv, ":n:o:e:")) != -1) {
        switch (opt) {
            case 'n':
            sscanf(optarg, "%d", &n);
            break;
            case 'o':
            fd_o = open(optarg, O_WRONLY | O_CREAT | O_TRUNC, 0777);
            dup2(fd_o, STDOUT_FILENO);
            break;
            case 'e':
            fd_e = open(optarg, O_WRONLY | O_CREAT | O_TRUNC, 0777);
            dup2(fd_e, STDERR_FILENO);
            break;
            case '?':
            fprintf(stderr, "Unknown option: %c\n", optopt);
            return EXIT_FAILURE;
            break;
            case ':':
            fprintf(stderr, "Missing arg for %c\n", optopt);
            return EXIT_FAILURE;
            break;
        }
    }

    for (int i = 0; i < n; i++){
        fprintf(stdout, "%d ", 1 + rand() % 10);
    }
    fputc(stdout, '\n');

    for (int i = 0; i < n; i++){
        fprintf(stderr, "%d ", 1 + rand() % 10);
    }
    fputc(stderr, '\n');
    if(fd_e != -1){
        close(fd_e);
    }
    if(fd_o != -1){
        close(fd_o);
    }
    return EXIT_SUCCESS;
}