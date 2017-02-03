#include<stdio.h>
#include<ctype.h>
#include <stdlib.h>

#define MAX 50


// forward declaration
void enqueue(char x);
char dequeue();
char front();
int isEmpty();
void printQ();
int open();
void inputc();
void test();

// global variable
char* array;
int head;
int rear;

int main() {
    array = malloc(sizeof (char) * MAX);
    head = rear = -1;

//    test();
    inputc();

    return 0;
}

void enqueue(char x) {
    // if queue is empty, head and rear points to new Node
    if (isEmpty()) {
        head = rear = 0;
    }
    if (open()) {
        array[rear] = x;
        rear = (rear + 1) % MAX;
    }

}

char dequeue() {
    if (!isEmpty) {
        printf("Queue is empty");
        return '\0';
    }
    //check and clear empty array before incrementing head
    if (head == rear)
        head = rear = -1;
    char temp = array[head];
    head = (head + 1) % MAX;

    return temp;
}

char front() {
    return array[head];
}

int isEmpty() {
    return (head == -1 || rear == -1);
}

void printQ() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    int p = head;
    while (p != rear) {
        printf("%c ", array[p]);
        p = (p + 1) % MAX;
    }
    printf("\n");
}

int open() {
    // check if rear == (head - 1)
    int x = (head - 1 + MAX) % MAX;
    return rear - x;
}

void inputc(){
            int cont = 1;
        char x;
        while (cont && open()) {
            printf("Enter character to queue: \n");
            fflush(stdout);
            scanf("%c", &x);
            getchar();
            enqueue(x);
            printf("You added %c to queue: \nAdd another character? 0 = No, 1 = Yes", x);
            fflush(stdout);
            scanf("%d", &cont);
            getchar();
        }

        printQ();

        printf("Dequeue? Yes: 1, No: 0 \n");
            fflush(stdout);
            scanf("%d", &cont);
            getchar();
        while (cont && !isEmpty()) {
            dequeue();
            printQ();
            printf("Dequeue? 0 = exit");
            fflush(stdout);
            scanf("%d", &cont);
            getchar();
        }
}

void test() {
    enqueue('a');
    printQ();
    enqueue('b');
    printQ();
    enqueue('c');
    printQ();
    enqueue('d');
    printQ();
    enqueue('e');
    printQ();
    enqueue('f');
    printQ();
    dequeue();
    dequeue();
    printQ();
    enqueue('g');
    printQ();
    enqueue('h');
    printQ();
    printf("dequeue all\n");
    dequeue();
    printQ();
    dequeue();
    printQ();
    dequeue();
    printQ();
    dequeue();
    printQ();
    dequeue();
    printQ();
    dequeue();
    printQ();
    enqueue('a');
    printQ();
    enqueue('b');
    printQ();
    enqueue('c');
    printQ();
    enqueue('d');
}
