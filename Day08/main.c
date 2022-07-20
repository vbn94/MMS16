#include <stdio.h>
#include <randoms.h>

int main(){
    randinit();
    printf("Rand max: %d\n", RAND_MAX);
    for (int i = 0; i < 10; i++){
        //printf("%.2lf\n", randreal(1.5, 5.2));
        printf("%c\n", randint('a', 'z'));
    }
}
