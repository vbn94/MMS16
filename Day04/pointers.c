#include <stdio.h>
#include <stdint.h>

int main(void){
    int num = 20;
    double pi = 3.14;
    char sym = 'z';
    int *ptri = &num;
    double *ptrd = &pi;
    char *ptrc = &sym;
    printf("%p\n", ptri);
    printf("%p\n", ptrd);
    printf("%p\n", ptrc);
    printf("%lu\n", sizeof(ptri));
    printf("%lu\n", sizeof(ptrd));
    printf("%lu\n", sizeof(ptrc));
    return 0;
}