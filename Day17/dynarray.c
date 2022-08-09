#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// #define ROWS 10

int main(){
    int i = ROWS;
    srand(time(NULL));    
    int n, m;
    scanf("%d %d", &n, &m);

    double matrix1[10][15];

    double** matrix = malloc(n * sizeof(double*));

    if (NULL == matrix){
        fprintf(stderr, "memory error!\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < n; i++){
        matrix[i] = malloc(m * sizeof(double));
        if (NULL == matrix[i]){
            fprintf(stderr, "memory error!\n");
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            matrix[i][j] = (rand() % 10) / 10.0;
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%.2f ", matrix[i][j]);
        }
        putchar('\n');
    }

    for (int i = 0; i < n; i++){
        free(matrix[i]);
    }
    free(matrix);

    return EXIT_SUCCESS;
}