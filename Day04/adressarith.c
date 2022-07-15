#include <stdio.h>
#include <stdint.h>

int main(void){
    uint64_t num = 20;
    uint64_t* p = &num;
    printf("%lu\n", p);
    printf("%lu\n", p + 1);
    printf("%lu\n", p + 10);
    return 0;
}