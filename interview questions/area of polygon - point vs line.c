#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
}point;

typedef enum{
    INLINE, LEFT, RIGHT
} turn;

double crossProduct(point a, point b);
double area(point vertices[] , int n);
turn pointDirection(point a, point b, point p);
point subtract(point a, point b);
void printDirection(turn t);

int main() {
    point data[] = {
        { 2, 3},
        { 4, 6},
        { 8, 12}
    };
//    double d = area(data, 3);
//    printf("area: %lf\n", d);
    turn trn = pointDirection(data[0], data[1], data[2]);
    printDirection(trn);
    return (0);
}

// determinant of a matrix
double crossProduct(point a, point b) {
    // use arrows for assignment struct->value
    // use dot to access struct.value
    return (a.x * b.y) - (a.y * b.x);
}

double area(point vertices[] , int n) {
    double sum = 0.0;
    // chop each polygon edge into a triangle with 3rd vertex at origin
    for(int i = 0; i <=n; i++){
        // vector product right-hand rule:
        // triangle points must either be all clockwise or counter-clockwise
        sum += crossProduct(
                vertices[i],
                vertices[(n+1)%n]);
    }
    return fabs(sum/2.0); //abs() will return int
}

turn pointDirection(point a, point b, point p) {
    // modify line ab so a is at origin
    b = subtract(b, a);
    p = subtract(p, a);

    // right hand rule: counter-clockwise vectors has positive crossproduct
    double cp = crossProduct(b, p);

    if(cp > 0)
        return LEFT;
    else if (cp < 0)
        return RIGHT;
    else
        return INLINE;
}

// subtract second point from first
point subtract(point a, point b) {
    point new;
    new.x = a.x - b.x;
    new.y = a.y - b.y;
}

void printDirection(turn t) {
    if(t == INLINE)
        printf("Point is on the line\n");
    else if(t == LEFT)
        printf("Point is left of line\n");
    else if(t==RIGHT)
        printf("Point is right of line\n");
}
