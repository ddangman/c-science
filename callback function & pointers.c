/*Function-pointers can be passed as arguments to functions
 functions receiving function-pointer as arguments can call back the function that the pointer points to*/
#include <stdio.h>
#include<math.h>
#include <stdlib.h>

typedef enum{
    INC, DEC
}FLAG;

//forward declaration
void sort(int[], int n, FLAG flag);
void bettersort(int arrptr[], int n, int(*compare)(int, int));
int compareinc(int a, int b);
int comparedec(int a, int b);
int compare(const void* a, const void* b);
void test();

//a function that takes no argument and returns void
void callbackfunc() {
    printf("Hello World\n");
}

// function that takes function-pointer as argument
// *ptr should point to a function that takes no argument and returns void
void callbackptr(void (*ptr)()) { // function pointer as argument
    ptr(); //call-back function that "ptr" points to
}

int main() {
    // declare a function-pointer that points to a function that takes no argument and returns void
    // initialize it to address of callbackfunc
    // because name of function returns a pointer
    void (*localptr)() = callbackfunc;
    callbackptr(localptr); // pass function-pointer to function

    // another way of writing functioncallback(function_pointer)
    callbackptr(callbackfunc);

    test();

    return (0);
}

// can also use int *arrptr == arrptr[]
void sort(int arrptr[], int n, FLAG f) {
    int i,j,temp;
    for(i=0; i<n; i++)
        for(j=0; j<n-1; j++) {
            /* checks for increasing flag && larger value before
               || checks for decreasing flag && smaller value before */
            if((arrptr[j] > arrptr[j+1] && f == INC)
                    || (arrptr[j] < arrptr[j+1] && f == DEC) ) {
                temp = arrptr[j];
                arrptr[j] = arrptr[j+1];
                arrptr[j+1] = temp;
            }
        }
}

// sorting function that takes function-pointer as argument
void bettersort(int *arrptr, int n, int(*compare)(int, int)) {
     int i,j,temp;
    for(i=0; i<n; i++)
        for(j=0; j<n-1; j++) {
            // comparison done using callback-function
            // callback-function must take 2 int arguments
            if(compare(arrptr[j], arrptr[j+1]) > 0) {
                temp = arrptr[j];
                arrptr[j] = arrptr[j+1];
                arrptr[j+1] = temp;
            }
        }
}

// callback-function for stdlib.qsort
// qsort uses a generic design to sort any array, so it
// uses void* pointers since it can be typecast to a pointer of any data type
// elements are passed by reference meaning addresses are being passed through a pointer
// const keyword means you cannot modify the address in the pointer variable
int compare(const void* a, const void* b) {
    //typecast element from void pointer to int pointer
    // int A = (int*)a;
    // then use *() to dereference and get the value
    int A = *( (int*)a );
    int B = *( (int*)b );
    return A-B;
}

//callback-function
// return 1 if first element has higher rank
// return 0 if elements are equal
// and -1 if second element has higher rank
int compareinc(int a, int b) {
    if (a > b)
        return 1;
    if (a < b)
        return -1;
    else
        return 0;
}

//callback-function
// return -1 if first element has higher rank
// return 0 if elements are equal
// and 1 if second element has higher rank
int comparedec(int a, int b) {
    if (a > b)
        return -1;
    if (a < b)
        return 1;
    else
        return 0;
}



//callback-function
// return 1 if first element has higher rank
// return 0 if elements are equal
// and -1 if second element has higher rank
int compareabs(int a, int b) {
    if (abs(a) > abs(b))
        return 1;
    if (abs(a) < abs(b))
        return -1;
    else
        return 0;
}

void test() {
    int array[] = {5,6,4,7,8,2,9,1,3};
    int array2[] = {5,6,-4,-7,8,2,-9,-1,3};

    sort(array, 9, INC);
    for(int i = 0; i < 9; i++)
        printf("%d ", array[i]);

    printf("\n");
    sort(array, 9, DEC);
    for(int i = 0; i < 9; i++)
        printf("%d ", array[i]);

    printf("\n");
    bettersort(array, 9, compareinc);
    for(int i = 0; i < 9; i++)
        printf("%d ", array[i]);

    printf("\n");
    bettersort(array, 9, comparedec);
    for(int i = 0; i < 9; i++)
        printf("%d ", array[i]);

    printf("\n");
    bettersort(array2, 9, compareabs);
    for(int i = 0; i < 9; i++)
        printf("%d ", array2[i]);
    printf("\n");

    // quick sort from stdlib
    qsort(array2,9, sizeof(int), compare);
    for(int i = 0; i < 9; i++)
        printf("%d ", array2[i]);
}
