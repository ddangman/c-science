#include <stdio.h>
#include <stdlib.h>

#define MAX 30

char* dtb(int n);
char* dto(int n);
char* dth(int n);
void reverse(char* s);

int main() {
    dtb(111);
    dto(111);
    dth(111);

    return (0);
}

// Decimal To Binary
char* dtb(int n) {
    char* s = (char*) malloc(sizeof (char) * MAX);
    int i = 0;
    while (n > 0) {
        s[i++] = n % 2 + '0';
        n = n / 2;
    }
    s[i] = '\0';
    reverse(s);
    printf("\n%s", s);
    return s;
}

// Decimal to Octal
char* dto(int n) {
    char* s = (char*) malloc(sizeof (char) * MAX);
    int i = 0;
    while (n > 0) {
        s[i++] = n % 8 + '0';
        n = n / 8;
    }
    s[i] = '\0';
    reverse(s);
    printf("\n%s", s);
    return s;
}

// Decimal to Hexadecimal
char* dth(int n) {
    char* s = (char*) malloc(sizeof (char) * MAX);
    int i = 0;
    int t;
    while (n > 0) {
        t = n % 16;
        if (t < 10)
            s[i++] = t + '0';
        else
            s[i++] = t + 'A' - 10; // correct for t > 10
        n = n / 16;
    }
    s[i] = '\0';
    reverse(s);
    printf("\n%s", s);
    return s;
}

void reverse(char* s) {
    int i, j;
    i = j = 0;
    char temp;
    // reach last char
    while (s[j] != '\0')
        j++;
    j--; // step in front of NULL
    // swap
    while (i < j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}
