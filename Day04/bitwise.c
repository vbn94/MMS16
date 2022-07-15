#include <stdio.h>
#include <stdint.h>

int main(){
    uint16_t mask = 0;
    int bit = 1;
    mask |= (1 << bit);
    bit = 5;
    mask |= (1 << bit);
    bit = 10;
    mask |= (1 << bit);
    bit = 14;
    mask |= (1 << bit);
    bit = 10;
    mask &= ~(1 << bit);
    for (int bit = sizeof(mask) * __CHAR_BIT__ - 1; bit >= 0 ; bit--){
        printf("%d", !!(mask & (1 << bit)));
    }
    putchar('\n');
    printf("%lu\n", (1ULL << 40));
    return 0;
}