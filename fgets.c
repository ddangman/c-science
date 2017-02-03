#include <stdlib.h>
#include <stdio.h>

void concat(char* original, char* append);
int main() {
    char* orig;
    char* apnd;
    orig = malloc(sizeof(char) * 100);
    apnd = malloc(sizeof(char) * 100);
    printf("enter original string");
    fflush(stdout);
    fgets(orig, 100, stdin);
    printf("enter appending string");
    fflush(stdout);
    fgets(apnd, 100, stdin);
    concat(orig, apnd);
    printf("%s", orig);
    return 0;
}

void concat(char* original, char* append) {
    //use '\n' since fgets records newline into char*
    while(*original != '\n') {
        original++;
    }
    // != '\n' or '\o' will work here
    while(*append) {
        *original = *append;
        append++;
        original++;
    }
}
