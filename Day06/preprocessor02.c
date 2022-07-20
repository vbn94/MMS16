#include <stdio.h>

//#define DEBUG 
#define SUM(a,b) ((a)+(b))
int main(){

    #if !(SUM(10,3) < 100 && OS > 3)
        printf("Super");
    #endif

    int a = 10;

    #ifdef DEBUG
      printf("debugging mode on!\n");
    #endif

    
    #define OS 1
    #ifdef OS
        #if OS == 1
        printf("Hello, Linux\n");
        #elif OS == 2
        printf("Hello, Windows\n");
        #else
        printf("Hello, macOS\n");
        #endif
    #else
        printf("OS is not defined!\n");
    #endif

    #undef OS
    #define OS 2

     #ifdef OS
        #if OS == 1
        printf("Hello, Linux\n");
        #elif OS == 2
        printf("Hello, Windows\n");
        #else
        printf("Hello, macOS\n");
        #endif
    #else
        printf("OS is not defined!\n");
    #endif

    return 0;
}