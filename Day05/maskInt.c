#include <stdio.h>
#include <stdint.h>

int setBit(uint32_t*,size_t,size_t);
int clearBit(uint32_t *,size_t,size_t);
int flipBit(uint32_t*,size_t,size_t);
int checkBit(uint32_t*,size_t,size_t);
void printMask(uint32_t*,size_t);

#define LEN 2

int main(void){
    uint32_t mask[] = {0, 0};
    if (setBit(mask, LEN, 2)){
        fprintf(stderr, "setbit: mask overflow error!\n");
    }
    if (setBit(mask, LEN, 63)){
        fprintf(stderr, "setbit: mask overflow error!\n");
    }
    if (setBit(mask, LEN, 10)){
        fprintf(stderr, "setbit: mask overflow error!\n");
    }
    if (clearBit(mask, LEN, 10)){
        fprintf(stderr, "clearbit: mask overflow error!\n");
    }
    if (flipBit(mask, LEN, 10)){
        fprintf(stderr, "flipbit: mask overflow error!\n");
    }
    if (setBit(mask, LEN, 10345)){
        fprintf(stderr, "setbit: mask overflow error!\n");
    }
    printMask(mask, LEN);
    return 0;
}


int setBit(uint32_t *mask, size_t n, size_t bit){
    if (n * sizeof(*mask)*__CHAR_BIT__ <= bit){
        return 1;
    }
    int index = bit / (sizeof(*mask) * __CHAR_BIT__);
    int b = bit % (sizeof(*mask) * __CHAR_BIT__);
    mask[index] |= (1ull << b);
    return 0;
}

int clearBit(uint32_t *mask, size_t n, size_t bit){
    if (n * sizeof(*mask)*__CHAR_BIT__ <= bit){
        return 1;
    }
    int index = bit / (sizeof(*mask) * __CHAR_BIT__);;
    int b = bit % (sizeof(*mask) * __CHAR_BIT__);
    mask[index] &= ~(1ull << b); 
    return 0;
}

int flipBit(uint32_t *mask, size_t n, size_t bit){
    if (n * sizeof(*mask)*__CHAR_BIT__ <= bit){
        return 1;
    }
    int index = bit / (sizeof(*mask) * __CHAR_BIT__);;
    int b = bit % (sizeof(*mask) * __CHAR_BIT__);
    mask[index] ^= (1ull << b);
    return 0; 
}

int checkBit(uint32_t *mask, size_t n, size_t bit){
    if (n * sizeof(*mask)*__CHAR_BIT__ <= bit){
        return -1;
    }
    int index = bit / (sizeof(*mask) * __CHAR_BIT__);;
    int b = bit % (sizeof(*mask) * __CHAR_BIT__);
    return !!(mask[index] & (1ull << b)); 
}

void printMask(uint32_t* mask, size_t n){
    for (int i = n * sizeof(*mask) * __CHAR_BIT__ - 1; i >= 0; i--){
        printf("%2d ", i);
    }
    putchar('\n');
    for (int i = n * sizeof(*mask) * __CHAR_BIT__ - 1; i >= 0; i--){
        printf("%2d ", checkBit(mask, n, i));
    }
    putchar('\n');
}

