#include <stdio.h>

int sum(int a, int b){
    return a + b;
}

int sub(int a, int b){
    return a - b;
}

int mult(int a, int b){
    return a * b;
}

int div(int a, int b){
    return a / b;
}

typedef int (*operation_t)(int,int);

operation_t getOp(char op){
//int (*getOp(char op))(int, int){
    switch (op){
        case '+':
            return sum;
        case '-':
            return sub;
        case '*':
            return mult;
        case '/':
            return div;
        default:
            return NULL;
    }
}

typedef unsigned int liters_t;


int main(){
    liters_t rakiaBottle;
    operation_t fp;
    fp = sum;
    
    return 0;
}