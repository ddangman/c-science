#include <stdio.h>

int main() {
    int a, b, c, d, e, f;
    float g, h;
    a = 5;
    b = a++; // post-operation equals to:
    // b = a; used in expression
    // a = a +1; then operation
    c = 5;
    d = --c; // pre-operation equals to:
    // c = c -1; operation then
    // d = c; used in expressionexpression

    e = a == b;
    f = c == d;

    g = a / c;
    h = 1.0 * a / c;

    printf("%d\n", a); //6
    printf("%d\n", b); //5 since POST-increment occurs AFTER assignment
    printf("%d\n", c); //4
    printf("%d\n", d); //4 PRE-decrement operation before assignment

    printf("%d\n", e); //0 since a == b is false(0) and == runs before assignment(higher priority)
    printf("%d\n", f); //1 since c == d is true(1). C doesn't have boolean CONSTANTS, it uses 1==TRUE, 0==FALSE

    printf("%f\n", g); //1.0 since int function rounds down before assignment (where cast happens)
    printf("%f\n", h); //1.5 since (1.0 *) casts int to float/double before operation
    return 0;
}
