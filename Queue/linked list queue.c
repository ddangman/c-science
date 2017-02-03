#include<stdio.h>
#include<ctype.h>
#include <stdlib.h>

typedef struct {
    char value;
    struct Node* next;
} Node;
// forward declaration
void enqueue(char x);
char dequeue();
char front();
int isEmpty();
void printQ();

// global variable
Node* head;
Node* rear;

int main() {
    head = NULL;
    rear = NULL;
    int cont = 1;
    char x;
    while (cont) {
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
    while (cont && head != NULL) {
        dequeue();
        printQ();
        printf("Dequeue? 0 = exit");
        fflush(stdout);
        scanf("%d", &cont);
        getchar();
    }
    return 0;
}

void enqueue(char x) {
    Node* new = malloc(sizeof (Node));
    new->value = x;
    new->next = NULL;
    // if queue is empty, head and rear points to new Node
    if (head == NULL && rear == NULL) {
        head = rear = new;
        return;
    }
    // point rear to new Node
    rear->next = new;
    // move rear to new Node
    rear = new;
}

char dequeue() {
    if (head == NULL)
        return '\0';
    Node* temp = head;
    head = head->next;
    return temp->value;
}

char front() {
    if (head == NULL)
        return '\0';
    return head->value;
}

int isEmpty() {
    if (head == NULL)
        return 1;
    return 0;
}

void printQ() {
    printf("Queue: \n");
    fflush(stdout);
    Node* temp = head;
    while (temp != NULL) {
        printf("%c ", temp->value);
        temp = temp->next;
    }
}
