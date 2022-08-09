#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));    
    int n;
    scanf("%d", &n);
    int* arr = malloc(n * sizeof(int));
    if (NULL == arr){
        fprintf(stderr, "Memory error!\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < n; i++){
        arr[i] = rand() % 10;
    }
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    putchar('\n');
    free(arr);
    return EXIT_SUCCESS;
}