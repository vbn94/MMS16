#include <stdio.h>
#include "mymath.h"

int num = 20;

// pure function
static int f1(int x){
    return 2 * x + 1;
}

// side effects
static int f2(int x){
    return 2 * x + num;
}

// side effects
int f3(int x){
    num++;
    return 2 * x + 1;
}


void counter(){
    static int num = 0;
    num++;
    printf("Num = %d\n", num);
}

int main(){
    //sum(10, 20);
    /*printf("f2(10) = %d\n", f2(10));
    num = 1;
    printf("f2(10) = %d\n", f2(10)); */
    counter();
    counter();
    counter();
    counter();
    return 0;
}