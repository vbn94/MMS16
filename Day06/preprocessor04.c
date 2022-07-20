#include <stdio.h>

#define PI 3.14
#pragma pack(1)

int main(){
    printf("%s\n", __FILE__);
    printf("%s\n", __TIME__);
    printf("%s\n", __TIMESTAMP__);
    printf("%d\n", __STDC__);
    printf("%d\n", __LINE__);
    return 0;
}