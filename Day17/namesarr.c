#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COUNT 5

int randint(int min, int max){
    return min + rand() % (max - min + 1);
}

int main(){
    srand(time(NULL));
    char **names = malloc(COUNT * sizeof(char*));
    if (NULL == names){
        fprintf(stderr, "memory error!\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < COUNT; i++){
        int len = randint(5, 20);
        names[i] = malloc((len + 1) * sizeof(char));
        if (NULL == names[i]){
            fprintf(stderr, "memory error!\n");
            return EXIT_FAILURE;
        }
        names[i][0] = randint('A', 'Z');
        for (int j = 1; j < len; j++){
            names[i][j] = randint('a', 'z');
        }
        names[i][len] = '\0';
    }

    for (int i = 0; i < COUNT; i++){
        printf("%s\n", names[i]);
    }

    for (int i = 0; i < COUNT; i++){
        free(names[i]);
    }
    free(names);
    return EXIT_SUCCESS;
}