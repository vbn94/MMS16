#include <stdio.h>

#pragma pack(1)

int main(){
    #ifdef OS
        #if OS == 1
        printf("Hello, Linux\n");
        #elif OS == 2
        printf("Hello, Windows\n");
        #elif OS == 3
        printf("Hello, macOS\n");
        #else
         #warning OS is not in range
        #endif
    #else
        #error OS is not defined!
    #endif
    return 0;
}