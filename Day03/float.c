#include <stdio.h>
#include <math.h>

#define EPS 0.001

int main(){
    /*
    float num1 = .0f;
    printf("%.35f\n", num1);12344455543455
    printf("float size: %lu\n", sizeof(num1));
    double num2 = 12344455543455;
    printf("%.35lf\n", num2);
    printf("double size: %lu\n", sizeof(num2));
    */
    double num1 = 1.1;
    double num2 = 0;

    for (int i = 0; i < 11; i++){
        num2 += 0.1;
    }
    printf("num1 = %.20lf\nnum2 = %.20lf\n", num1, num2);
    if (fabs(num1 - num2) < __DBL_EPSILON__*max(fabs(num1), fabs(num2))){
        printf("Equals\n");
    } else {
        printf("Not equals\n");
    }
    return 0;
}