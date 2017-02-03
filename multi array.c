#include <stdio.h>

int main(void) {
    int ar[5] = {11, 22, 33, 44, 55};
    printf("%d %d\n", *ar, 0[ar]);
    printf("%d %d\n", *(ar+1), 1[ar]);
    printf("%d %d\n", *(ar+2), 2[ar]);
    printf("%d %d\n", *(ar+3), 3[ar]);

    int* p1;
    int* p2;
    p1 = ar;
    p2 = ar +2;
    printf("%d\n", *p2);
    printf("%d\n", p2);
    printf("%d\n", &ar[2]);
    printf("%d\n", &p2);
    for(int i =0; i < 5; i++) {
      // i[ar] == ar[i]
        printf("%d %d\n", i[ar], &i[ar]);
    }

    int ar1[2][3] = {{100, 200, 300}, {111, 222, 333}};
    int ar2[2][3] = {100, 200, 300, 111, 222, 333};
    int (*ptr)[3];
    ptr = ar1;
    printf("%d %d\n", ptr[1][1], *(*(ptr+0)+2));
    return 0;

}
