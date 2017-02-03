/*The scanf function removes whitespace automatically before trying to parse things other than characters.
 %c, %n, %[] are the 3 specified expectations that do not discard whitespace, leading or not.
 any combination of whitespace (newline, space, tab) can be used separate consecutive scanf that ignores whitespace
 invalid input will roll over to the next statement where it can be caught by another input function
 to capture whitespaces in char arrays, use gets() */
#include <stdio.h>

int main() {
    int a, b, c;

    printf("Enter 3 integers separated by space or newline\n");
    fflush(stdout);
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    printf("%d %d %d", a, b, c);
    return 0;
}
/* getchar() echos character but must be followed by enter key
getch will not echo character. Is read instantly w/o waiting for enter key
getche will echo (suffix e == echo). Is read instantly w/o waiting for enter key like getch
getc gets next unsigned char from specified stream and advances position indicator of that stream
echo means that when you type a character, it prints to the screen so you can see what you typed*/
void gets_Info() {
    int a;
    char b[20];

    printf("Input your ID: ");
    scanf("%d", &a);

    // scanf("%d") leaves behind newline that will be caught by gets()
    // instead of accepting keystroke from user
    getc(stdin);

    // alternative
    getchar(); // reads the newline character

    printf("Input your name: ");
    gets(b); //reads whitespace
}
