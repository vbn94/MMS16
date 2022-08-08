#include <stdio.h>

// char **argv, char *argv[]
int main(int argc, char *argv[]){
    // argc -> ARGuments Count
    // argv -> ARGuments Vector/Values
    printf("Arguments count: %d\n", argc);
    for (int i = 0; i < argc; i++){
        printf("argv[%d] = %s\n", i, argv[i]);
    }

   /* int n = 0;
    while (argv[n]){
        printf("argv[%d] = %s\n", n, argv[n]);
        n++;
    }*/
    return 0;
}