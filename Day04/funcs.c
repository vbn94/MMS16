#include <stdio.h>
#include <stdint.h>

void sayHello(void){
    printf("Hello\n");
}

void sayHelloN(int n){
    for (int i = 0; i < n; i++){
        printf("Hello\n");
    }
}

void setZero(int* a){
    *a = 0;
}

void swapNums(int* num1, int* num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int main(void){
    int a = 10, b = 20;
    swapNums(&a, &b);
    //sayHello();
    //sayHelloN(4);
    int num = 20;
    setZero(&num);
    printf("Num = %d\n", num);
    /*int *ptr; 
    ptr = &num;
    printf("%p\n", ptr);
    printf("%d\n", *ptr);*/
    return 0;
}