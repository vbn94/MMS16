#include <stdio.h>
#include <stdint.h>

void printValue(void *value, int type){
    // 1 -> int, 2 -> double, 3-> char
    if(1 == type){
        printf("Value: %d\n", *(int*)value);
    } else if (2 == type){
        printf("Value: %.2lf\n", *(double*)value);
    } else if (3 == type){
        printf("Value: %c\n", *(char*)value);
    }
}

int main(void){
    int num = 20;
    double pi = 3.14;
    char sym = 'Z';
    void *ptr;
    ptr = &num;
    printf("%p\n", ptr);
    ptr = &pi;
    printf("%p\n", ptr);
    ptr = &sym;
    printf("%p\n", ptr);
    printf("%c\n", ptr);
    return 0;
}