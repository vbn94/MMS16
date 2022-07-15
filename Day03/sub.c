#include <stdio.h>
#include <stdint.h>

int main(){
    /*int a, b, c;
    a = 45;
    b = 18;
    c = a << 56;*/
    uint16_t mask = 0xff;
    int bit = 0;
    printf("%d\n", !!(mask & (1 << bit)));
    return 0;
}