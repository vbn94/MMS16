#include <stdio.h>
#include <stdbool.h>

#define PI 3.14
#define mydouble double
#define SUM(x,y) ((x)+(y))
#define MULT(x,y) ((x)*(y))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)>(b)?(b):(a))
#define FORI(start,end,step) for(int i = start; i <= end; i += step)
#define FOR(var, start,end,step) for(int var = start; var <= end; var += step)
#define SWAP(a,b) {a ^= b; \
                   b ^= a; \
                   a ^= b;}
#define MAX4(a,b,c,d) MAX(MAX(a,b),MAX(c,d))
#define CIRCLEAREA(r) (PI*(r)*(r))
#define SETBIT(mask,bit) mask|=(1ull<<(bit))
#define CLEARBIT(mask,bit) mask&=~(1ull<<(bit))
#define FLIPBIT(mask,bit) mask^=(1ull<<(bit))
#define CHECKBIT(mask,bit) (mask & (1ull<<(bit))>>(bit))

#define PRINTNAME(name) printf("Name is: %s\n", #name)
#define PRINTINT(num) printf("%s = %d\n", #num, num)
#define PRINTNUM(n) printf("%d\n", num##n)

int max(int a, int b){
    return a > b ? a : b;
}

int main(){
    int num1 = 20, num2 = 30, num3 = 56, num5 = 100;
    
    // PRINTNUM(i); // => printf("%d\n", numi)
    int number = 100;
    PRINTINT(number);
    PRINTNAME(Ivan);

    bool isOdd = true;
    if (isOdd){
        printf("True\n");
    } else {
        printf("False\n");
    }
    /*int a = 20;
    int b = 30;
    int c = MAX(a++, b++);
    printf("a = %d, b = %d, c = %d\n", a, b, c);



    /*printf("%d %d\n", a, b);
    SWAP(a, b);
    printf("%d %d\n", a, b);
    FORI(1, 100, 2){
        printf("%d\n", i);
    }

    mydouble r = 10;
    double S = PI * r * r;
    double P = 2* PI * r;
    printf("S = %.2lf\n", S);
    printf("P = %.2lf\n", P);
    int result1 = SUM(10, 20) * 2;
    int result2 = MULT(5+1, 1+3); // (5+1 * 1 + 3)
    printf("Result1 = %d\n", result1);
    printf("Result2 = %d\n", result2);
    int result3 = MIN(10, 20);
    double result4 = MIN(5.3,3.1);
    printf("Result3 = %d\n", result3);
    printf("Result4 = %lf\n", result4); */
    return 0;
}