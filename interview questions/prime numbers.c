#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum {
    false, true
} bool;
// struct node == node
// to prevent Warning: assignment from incompatible pointer type
typedef struct node{
    int value;
    struct node* next;

}node;

bool isPrime(int n);
void printFactors(int n);
node* insertNext(node* n, int x);
node* insertRev(node* n, int x);
void printPrimes(int n);
void printPrimeBool(bool b);
void primeFactors(int x);
int gcd(int dividend, int divisor);
int gcdRecursive(int dividend, int divisor);
void test1();


int main() {
//    test1();
//    printPrimes(104);
//    printFactors(100);
//    primeFactors(36);
    int n = gcdRecursive(400, 124);
    printf("%d\n", n);

    n = gcdRecursive(124, 400);
    printf("%d\n", n);

    n = gcd(400, 124);
    printf("%d\n", n);

    n = gcd(124, 400);
    printf("%d\n", n);

    return (0);
}

bool isPrime(int n) {
    if(n<=0)
        return false;
    if(n <= 2)
        return true;
    int srt = sqrt(n);
    for(int i = 2; i <= srt; i++) {
        // condition for non-prime number
        if(n%i==0)
            return false;
    }
    return true;
}

void printFactors(int n){
    // initialize pointers
    node* pr = NULL; //pr: pointer reverse
    node* head = malloc(sizeof(node));
    head->next = NULL;
    head->value = 1;
    node* pup = head; // pup: pointer up

    int t;
    int sr = sqrt(n);
    for(int i = 2; i <sr; i++) {
        if(n%i==0) {
            pup = insertNext(pup, i);
            // insert cofactor in reverse
            t = n / i;
            pr = insertRev(pr, t);
        }
    }
    // insert square-root only once
    if(sr * sr == n)
        pup = insertNext(pup, sr);
    // merge linked list
    pup->next = pr;

    // print results
    printf("Factors of %d:\n", n);
    while(head != NULL){
        printf("%d ", head->value);
        pup = head; // mark node for deletion
        head = head->next; //advance head
        free(pup);
    }
    printf("%d\n", n);
}

node* insertNext(node* n, int x){
    node* new = malloc(sizeof(node));
    new->next = NULL;
    new->value = x;
    n->next = new;
    return new;
}

node* insertRev(node* n, int x) {
    node* new = malloc(sizeof(node));
    new->next = n;
    new->value = x;
    return new;
}

// find prime by Sieve of Eratosthenes
void printPrimes(int n){
    // array to track valid integers
    int* a = malloc(sizeof(int) * n); //stack doesn't take variable as array size
    //initialize all numbers as valid
    for(int i = 1; i <n; i++)
        a[i] = 1;
    // set invalid edge case
    a[0] = 0;

    int s = sqrt(n);
    for(int j = 2; j < s; j++) { // loop to sqrt
        // remove primes
        if(isPrime(j)) {
            // iterate multiples of factor to invalidate
            for(int k = 2; j * k < n; k++)
                a[j*k] = 0; //invalidate factor
        }
    }

    // print valid primes
    for(int l = 0; l <= n; l++)
        if(a[l])
            printf("%d ", l);
    if(isPrime(n))
        printf("%d\n", n);

    // reclaim memory
    free(a);
}

void printPrimeBool(bool b){
    if(b == true)
        printf(" is PRIME\n");
    else
        printf(" NOT prime\n");
}

void primeFactors(int x){
    printf("Prime Factors for %d: ", x);
    int count = 0;
    int sr = sqrt(x);
    for(int i = 2; i < x && i < sr; i++) {
        while(x%i==0){
            count++;
            x /= i;
        }
        if(count>0){
            printf("%d^%d " ,i, count );
            count = 0;
        }
    }
    if(x != 1)
        printf("%d^1\n", x);
    else
        printf("\n");

}

// Euclidean algorithm to find Greatest Common Divisor(GCD) of 2 integers
int gcd(int dividend, int divisor) {
    int remainder;
    while(divisor != 0) {
        remainder = dividend % divisor;
        dividend = divisor;
        divisor = remainder;
    }
    return dividend;
}


int gcdRecursive(int dividend, int divisor) {
    return divisor == 0 ? dividend : gcdRecursive(divisor, dividend % divisor);
}

void test1() {
        for(int i = 0; i < 15; i++){
        printf("%d", i);
        printPrimeBool(isPrime(i));
    }
}
