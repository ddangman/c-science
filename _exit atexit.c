/* int atexit(void (*func) (void)); returns 0 if fx registered successfully
 void exit(int status) causes the program to flush and exit normally;
 void _Exit(int exit_code); causes the program to exit IMMEDIATELY*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void onexit() {
    puts("this function should run before normal termination");
    getc(stdin); // used to pause after puts
}
int main ()
{
    if(atexit(onexit) != 0) {
        puts("failed to register onexit as a terminating function");
    }


    for(int counter = 0;;counter++) {
        printf("%d\n", counter);
        if (counter == 10) {
            _exit(0); // exits without running onexit
            exit(0); // exits after flushing onexit
        }
    }

    return (0);
}
