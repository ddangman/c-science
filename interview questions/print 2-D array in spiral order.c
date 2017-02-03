#include <stdio.h>
#include <stdlib.h>

typedef enum {
    RIGHT, DOWN, LEFT, UP
} dir;

void clockwise(char **a, int w, int h);
void countercw(char **a, int w, int h);

// prints 2-D array 'a' of width 'w' & height 'h' clockwise
void clockwise(char **a, int w, int h) {
    // declare boundaries: right, left, top, bottom
    int r, l, t, b;
    //set boundaries
    l = t = 0;
    r = w-1;
    b = h-1;

    // use int to allow arithmetic operations
    // enum is user defined and arithmetic operations aren't allowed due to bugs
    int d = RIGHT; // starting direction is right

    // loop ends when either vertical or horizontal limits are negative
    while( l <= r && t<= b){
        if(d == RIGHT) {
            for(int i = l; i <= r; i++) // iterate left to right
                printf("%c ", a[t][i]); // print top-row rightward
            t++; //lower top limit
        }
        else if(d == DOWN) {
            for(int i = t; i <= b; i++) // iterate top to bottom
                printf("%c ", a[i][r]); // print downward right-column
            r--; //decrease right limit
        }
        else if(d == LEFT) {
            for(int i = r; i >= l; i--) //iterate right to left
                printf("%c ", a[b][i]); // print bottom-row leftward
            b--; // raise bottom limit
        }
        else if(d == UP) {
            for(int i = b; i >= t; i--) // iterate bottom to top
                printf("%c ", a[i][l]); // print upward left-column
            l++; // increase left limit

        }
        // change direction
        d = (d+1)%4;

    }
}

void countercw(char **a, int w, int h){
        // declare boundaries: right, left, top, bottom
    int r, l, t, b;
    //set boundaries
    l = t = 0;
    r = w-1;
    b = h-1;

    // use int to allow arithmetic operations
    // enum is user defined and arithmetic operations aren't allowed due to bugs
    int d = DOWN; // starting direction is right

    // loop ends when either vertical or horizontal limits are negative
    while( l <= r && t<= b){
        if(d == DOWN) {
            for(int i = t; i <= b; i++) // iterate top to bottom
                printf("%c ", a[i][l]); // print downward left-column
            l++; //increase left limit
        }
        else if(d == RIGHT) {
            for(int i = l; i <= r; i++) // iterate left to right
                printf("%c ", a[b][i]); // print bottom-row rightward
            b--; // raise bottom limit
        }
        else if(d == UP) {
            for(int i = b; i >= t; i--) // iterate bottom to top
                printf("%c ", a[i][r]); // print upward right-column
            r--; // decrease right limit

        }
        else if(d == LEFT) {
            for(int i = r; i >= l; i--) //iterate right to left
                printf("%c ", a[t][i]); // print top-row leftward
            t++; // lower top limit
        }

        // change direction
        d = (d+3)%4; // +4 - 1 == +3 to prevent negative modulus bug

    }
}

int main() {
    int numRows = 5;
    int numCols = 5;
    char ** charAr; // 2d array

    //allocate an "ARRAY of arrays" of size char POINTERS
    charAr = malloc(numRows * sizeof(char*));

    // each entry in the array of arrays of char
    // isn't allocated yet, so allocate it
    for( int row = 0; row < numRows; row++)
        // allocate an array of char
        // for the arrays in the "array of ARRAYS"
        charAr[row] = malloc( numCols * sizeof(char));

    // fill array
    char letter = 'a';
    for(int row = 0; row < numRows; row++)
        for(int col = 0; col < numCols; col++)
            charAr[row][col] = letter++;

    // check if array is initialized
    for(int row = 0; row < numRows; row++)
        for(int col = 0; col < numCols; col++)
            printf("%c ", charAr[row][col]);
    printf("\n");

    clockwise(charAr, numCols, numRows);
    printf("\n");
    countercw(charAr, numCols, numRows);
    return (0);
}
