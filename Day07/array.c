#include <stdio.h>
#include <stdlib.h>
#include "randoms.h"

//#define COUNT 10

int compareInt1(const void* num1, const void* num2){
    return *(int*)num1 - *(int*)num2;
}

int compareInt2(const void* num1, const void* num2){
    return *(int*)num2 - *(int*)num1;
}

int main(){
    int (*myComparator)(const void*, const void*);
    myComparator = &compareInt1;
    printf("%p\n", myComparator);
    myComparator = &compareInt2;
    printf("%p\n", myComparator);
    randinit();
    int numbers[COUNT];
    for (int i = 0; i < COUNT; i++){
        numbers[i] = randint(-100, 100);
    }
    qsort(numbers, COUNT, sizeof(numbers[0]), myComparator);
    for (int i = 0; i < COUNT; i++){
        printf("%d ", numbers[i]);
    }
    putchar('\n');*/
    return 0;
}