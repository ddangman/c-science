#include <stdio.h>

/* typedef is optional.
 * using it allows you to call Weekday x
 * without it, you would have to call enum Weekday x
 */

typedef enum Weekday {
    // enum starts at 0 are assigned incrementally without holes
    // holes can be created by assignment such as Wed = 10, Thur will continue increment as 11
    Sun=1, Mon, Tues, Wed, Thur, Fri, Sat
} WEEKDAY; //declaring alias here allows you to call enum simply by WEEKDAY.
// typedef is required to assign alias
// if alias is declared, variable name Weekday can be omitted.
// terminating semicolon, required!
// above format also applies to union and struct
int main(void) {
    // usage if typedef is not included
    enum Weekday m;
    m = Mon;

    // usage if typedef storage class specifier is used
    Weekday w = Wed;

    // usage if declarator (simple name) is used
    WEEKDAY f = Fri;
    printf("%d\n%d\n%d", m, w, f);
    return 0;

}
