#include <stdio.h>
#include <math.h>

#define EPS 0.001

int main(){
    int a = 0;
    int b = 2;
    if ( 1 || a++ || a++ || a++ || a++ ){
        printf("True!\n");
    } else {
        printf("False!\n");
    }
    printf("a = %d\nb = %d\n", a, b);
    return 0;
}