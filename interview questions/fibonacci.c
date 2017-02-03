#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// global array of size == max
int F[51];

/*when writing recursion, you need a base-case (base condition where recursion stops)*/
int fib(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fib(n - 2) + fib(n - 1);
}

int fibprint(int n) {
    printf("++ calculating %d\n", n);
    if (n == 0) {
        printf("== returning 0\n");
        return 0;
    }
    if (n == 1) {
        printf("== returning 1\n");
        return 1;
    }
    printf(" + calling ( %d - 2 ) + ( %d - 1) \n", n, n);
    int f = fibprint(n - 2) + fibprint(n - 1);
    printf("== returning ( %d - 2 ) + ( %d - 1) \n", n, n);
    return f;
}

int fibmem(int n) {
    if (n > 51)
        printf("Max value is 50");
    if (F[n] != -1)
        return F[n];
    F[n] = fibmem(n-2) + fibmem(n-1);
    return F[n];
}

void initarray(){
    F[0] = 0;
    F[1] = 1;
    // initialize uncalculated fib sequence
    for(int i = 2; i < 51; i++)
        F[i] = -1;
}

int main() {
    initarray();
    printf("%d\n", fibmem(40));
    return (0);
}
