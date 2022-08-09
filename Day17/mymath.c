#include "mymath.h"

static int sum(int a, int b){
    return a + b;
}

int sub(int a, int b){
    return -sum(a, b);
}