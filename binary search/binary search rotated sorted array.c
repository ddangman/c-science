/* searching a circularly sorted array only works if all values are unique*/
#include <stdio.h>
#include <stdlib.h>

void test();
int countRotations(int arr[], int n);
int searchCirSortedArr(int arr[], int n, int x);

int main(int argc, char** argv) {
    test();
    return (EXIT_SUCCESS);
}

/*given a sorted array, determine how many times it has been rotated
 so that the lowest number(pivot) should be at array[0]*/
int countRotations(int arr[], int n) {
    int low = 0, mid, high = n - 1, next, prev;
    // low boundary should never be greater than high
    // if low == high then == mid and binary search is complete
    while (low <= high) {
        mid = low + (high - low) / 2;
        next = (mid + 1) % n;
        prev = (mid + n - 1) % n;
        // pivot number will be less than both adjacent numbers
        if (arr[mid] <= arr[prev]
                && arr[mid] <= arr[next])
            return mid;
        else if (arr[low] <= arr[high])
            return low;
        if (arr[low] <= arr[mid])
            low = mid + 1;
        else if (arr[high] >= arr[mid])
            high = mid - 1;
    }
    // n does not exist in array
    return -1;
}

int searchCirSortedArr(int arr[], int n, int x) {
    int low = 0, mid, high = n - 1;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[low] == x)
            return low;
        else if (arr[high] == x)
            return high;
            // if low half of array is sorted
            if (arr[low] < arr[mid])
                // if answer is within sorted range, set bounds to range
                if (arr[low] < x && x < arr[mid])
                    high = mid - 1;
                    // set bounds for other (high) half
                else
                    low = mid + 1;
                // if high half of array is sorted
            else if (arr[mid] < arr[high])
                // if answer is within sorted range
                if (arr[mid] < x && x < arr[high])
                    low = mid + 1;
                else
                    high = mid - 1;
    }
    return -1;
}

void test() {
    int x;
    int arr1[] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
        17, 18, 19, 20, 1, 2, 3, 4, 5}; //15
    int arr2[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
        17, 18, 19, 20, 1}; //19
    int arr3[] = {20, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
        17, 18, 19}; // 1
    int arr4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
        17, 18, 19, 20}; // 0

    x = countRotations(arr1, 20);
    printf("\n%d", x);
    x = countRotations(arr2, 20);
    printf("\n%d", x);
    x = countRotations(arr3, 20);
    printf("\n%d", x);
    x = countRotations(arr4, 20);
    printf("\n%d", x);

    x = searchCirSortedArr(arr1, 20, 6);
    printf("\n%d", x);
    x = searchCirSortedArr(arr2, 20, 1);
    printf("\n%d", x);
    x = searchCirSortedArr(arr3, 20, 6);
    printf("\n%d", x);
    x = searchCirSortedArr(arr4, 20, 21);
    printf("\n%d", x);
}
