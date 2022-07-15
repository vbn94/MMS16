#include <stdio.h>
#include <stdint.h>

void printArray(int *arr, int len){
    for (int i = 0; i < len; i++){
        printf("%d", arr[i]);
    }
    putchar('\n');
}

int main(void){
    int nums3[15];
    int nums[2];
    int nums2[10];
    for (int i = 0; i < 10; i++){
        scanf("%d", nums + i);
    }
    for (int i = 0; i < 10; i++){
        printf("%d ", *(nums + i));
    }
    putchar('\n');
    return 0;
}