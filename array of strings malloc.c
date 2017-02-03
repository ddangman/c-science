#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    // pointers use dynamic memory determinted at runtime,
       // runtime calculations can better manage memory
    // arrays use static memory determined at compile time
       // bad estimation can lead to wasted or insufficient memory (buffer overflow)
    char* messages[5];
    char* allstrings;
    int i;
    int total = 0;
    for(i = 0; i < 5; i++) {
        printf("Enter a string\n");
        fflush(stdout);
        // do not cast (char*) malloc(); in C
        // the void* pointer returned by malloc in C
        // is automatically converted to the correct type
        // if you want your code to compile with a C++ compiler, a cast is needed
        // .c == C source file
        // .cpp == C++ source file
        messages[i] = malloc(10*sizeof(char)); // assuming no more than 10 char input
        scanf("%s", messages[i]);
        total += strlen(messages[i]);
    }
    // must allocate memory for spaces concatenated to string
    // and '\0' string terminator
    // because using more memory than allocated may work
    // but will cause buffer overflow
    // which can overwrite data that should not be overwritten
    // your system will be at the mercy of the consequences of that memory write!
    allstrings = malloc ((total + 1 + 5) * sizeof(char));
    strcpy(allstrings, messages[0]);
    for (i = 1; i < 5; i++) {
        strcat(allstrings, " ");
        strcat(allstrings, messages[i]);
    }
    printf("%s", allstrings);
    fflush(stdout);

    free(allstrings);
    // above- free pointer to release memory
    // below- using loop to free memory is a waste of processing
    for(i=0;i<5;i++) {
        free(messages[i]);
    }
    return (EXIT_SUCCESS);
}
