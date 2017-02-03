/*Function-pointers can be passed as arguments to functions
 functions receiving function-pointer as arguments can call back the function that the pointer points to*/
#include <stdio.h>
#include<math.h>
#include <stdlib.h>

typedef enum {
    false, true
} bool;

//forward declaration
int compare(const void* a, const void* b);
int binarySearchIt(int* arr, int n, int x);
int findFirstBiSrch(int* arr, int n, int x);
int findLastBiSrch(int* arr, int n, int x);
int binarySearchBool(int arr[], int n, int x, bool searchFirst);
int repCount(int arr[], int n, int x);
void test();

int main() {
    test();
    return (0);
}

int binarySearchRe(int* arr, int x, int low, int hi) {
    if(low > hi)
        return -1;
    // same as (high + low) / 2
    // (high + low) may cause int overflow
    int mid = low + (hi - low) / 2;
    if (x == arr[mid])
        return mid;
    else if (x < arr[mid])
        return binarySearchRe(arr, x, low, mid -1);
    else if (x > arr[mid])
        return binarySearchRe(arr, x, mid+1, hi);
}

// arr == array to search, n == size of arr, x == number to find
int binarySearchIt(int* arr, int n, int x) {
    int low = 0;
    int mid;
    int hi = n - 1;
    while ( low <= hi) {
        // same as (high + low) / 2
        // (high + low) may cause int overflow
        mid = low + (hi - low) / 2;

        if (arr[mid] == x)
            return mid;

        // middle value is greater than x, change search boundaries to lower half
        else if (arr[mid] > x)
            hi = mid - 1;

        // middle value is less than x, change search boundaries to upper half
        else if (arr[mid] < x)
            low = mid + 1;
    }
    return -1;
}

int findFirstBiSrch(int* arr, int n, int x) {
    int low = 0;
    int mid;
    int hi = n - 1;
    // if match found, store in result
    // continue search until no prior result matches
    int result = -1;
    while ( low <= hi) {
        mid = low + (hi - low) / 2;

        // match found, check again
        if (arr[mid] == x){
            result = mid;
            hi = mid - 1;
        }

        else if (arr[mid] > x)
            hi = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;
    }
    return result;
}

int findLastBiSrch(int* arr, int n, int x) {
    int low = 0;
    int mid;
    int hi = n - 1;
    // if match found, store in result
    // continue search until no prior result matches
    int result = -1;
    while ( low <= hi) {
        mid = low + (hi - low) / 2;

        // match found, check again
        if (arr[mid] == x){
            result = mid;
            low = mid + 1;
        }

        else if (arr[mid] > x)
            hi = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;
    }
    return result;
}

// return first or last occurance of x based on searchFirst boolean
int binarySearchBool(int arr[], int n, int x, bool searchFirst){
    int low = 0, hi = n-1, result = -1, mid;
    while(low <= hi){
        mid = low + (hi-low) / 2;
        if(arr[mid] == x){
            result = mid;
            if(searchFirst)
                hi = mid - 1;
            else
                low = mid + 1;
        }
        else if(x < arr[mid])
            hi = mid - 1;
        else if(x > arr[mid])
            low = mid + 1;
    }
    return result;
}

// return count of int x in arr
int repCount(int arr[], int n, int x) {
    int first = binarySearchBool(arr, n, x, true);
    if(first == -1)
        return 0;
    int last = binarySearchBool(arr, n, x, false);
    return last - first + 1;
}

int compare(const void* a, const void* b) {
    int A = *(int*) a;
    int B = *(int*) b;
    return A - B;
}

void test() {
    int x;
    int array[] = {5, 6, 4, 7, 8, 2, 9, 1, 3, 10, 122,
        33, 144, 55, 166, 77, 188, 99, 1000, 35, 75, 82};

    int repArr[] = {1,2,2,2,2,2,2,2,2,2,2,2,2,2,3};

    // quick sort from stdlib
    qsort(array, 20, sizeof (int), compare);
    for (int i = 0; i < 20; i++)
        printf("%d ", array[i]);

    x = binarySearchIt(array, 20, 1000);
    printf("\n%d", x);
    x = binarySearchRe(array, 1000, 0, 20);
    printf("\n%d", x);

    x = binarySearchIt(array, 20, 1);
    printf("\n%d", x);
    x = binarySearchRe(array, 1, 0, 20);
    printf("\n%d", x);

    x = findFirstBiSrch(repArr, 15, 3);
    printf("\n%d", x);
    x = findLastBiSrch(repArr, 15, 3);
    printf("\n%d", x);

    x = repCount(repArr, 15, 2);
    printf("\n%d", x);
}
