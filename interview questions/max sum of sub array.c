#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int maxSubSumK(int a[], int n);
int Max_Subarray_Sum(int arr[],int n);
int maxi(int a, int b);

//Kadane's algorithm O(n) to find max sum possible of sub array
// a[] == array, n == array size
int maxSubSumK(int a[], int n) {
    if (n == 1)
        return a[0]; // return single value
    int sum, sm, max;
    sum = max = 0;
    sm = INT_MIN; // if no positive int, return single max
    for (int i = 0; i < n; i++){
        if(a[i] > sm)
            sm = a[i]; // assign single max
        if(sum + a[i] > 0){ // keep adding array as long as it's positive
            sum += a[i];
            max = maxi(sum, max);
        } else { // sum is below 0
            sum = 0;
        }
    }
    if(sm<=0)
        return sm;
    else
        return max;
}

// divide and conquer O(NlogN)
int Max_Subarray_Sum(int arr[], int n) {
    if (n == 1)
        return arr[0];
    // divide array
    int m = n / 2;
    // recursively call function for sub-arrays
    int left_MSS = Max_Subarray_Sum(arr, m);
    int right_MSS = Max_Subarray_Sum(arr + m, n - m);

    // add sum from center out
    int leftsum = INT_MIN, rightsum = INT_MIN, sum = 0;
    for (int i = m; i < n; i++) { //iterate from center forward
        sum += arr[i]; // add each iteration
        rightsum = maxi(rightsum, sum); // keep new sum or previous
    }
    sum = 0; //reset sum
    for (int i = (m - 1); i >= 0; i--) { // iterate from center backward
        sum += arr[i]; // add each iteration
        leftsum = maxi(leftsum, sum); // keep new sum or previous
    }
    // return greatest sum
    int ans = maxi(left_MSS, right_MSS);
    return maxi(ans, leftsum + rightsum);
}

int maxi(int a, int b){
    if(a>b)
        return a;
    return b;
}

int main() {
   int arr[] = {1, -3, 2, -5, 7, 6, -1, -4, 11, -23}; //19
   printf("%d\n", maxSubSumK(arr, 10));
   printf("%d\n", Max_Subarray_Sum(arr, 10));
   return (0);
}
