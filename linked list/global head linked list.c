/*global head version*/
#include <stdio.h>
#include <stdlib.h>

#define VERSION 2

typedef struct node {
    int value;
    struct node* next;
} Node;

// forward declaration
void insertf(int data);
void printlist();
void insertn(int data, int n);
void genlistsize();
void deleten(int n);
void reverselist(Node* pointer);
void testcode();

// global variable
Node* head;

int main() {
    // must initialize Node asap to prevent bugs later
    head = NULL;
    testcode();

    return (0);
}

// insert into first position

void insertf(int data) {
    Node* new = malloc(sizeof (Node));
    new->value = data;
    // assign new Node's pointer to next &Node == head(current)
    // if last Node, will copy NULL from head(current)
    new->next = head;
    // head(updated) now points to new &Node
    head = new;
}

// insert into n position

void insertn(int data, int n) {
    // n == 1 == (insertf)insert into first position
    if (n == 1) {
        insertf(data);
        return;
    }
    Node* new = malloc(sizeof (Node));
    new->value = data;
    new->next = NULL;
    // Transverse List Pointer should start traversing from head
    Node* tlp = head;

    for (int i = 0; i < n - 2; i++) {
        // if n exceeds list length, place data at end of list
        if (tlp->next == NULL) //tlp is on last Node
            break;
        tlp = tlp->next;
    }
    // after new Node is inserted
    // previous Node must be edited to point to new Node
    new->next = tlp->next;
    // point tlp to new Node
    tlp->next = new;
}

void printlist() {
    // temp created so actual head value isn't affected
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->value);
        // move pointer forward
        // lastPointer.next == NULL, so temp == NULL
        temp = temp->next;
    }
    printf("\n");
}

// delete node at n

void deleten(int n) {
    // Transverse List Pointer should start traversing from head
    Node* tlp = head;
    if (n == 1) {
        head = head->next;
        free(tlp);
        return;
    }
    // iterate until n-1
    for (int i = 0; i < n - 2; i++) {
        //move pointer forward
        tlp = tlp->next;
        if (tlp->next == NULL) {
            // n exceeds list length
            printf("Can not delete item at position greater than list length\n");
            fflush(stdout);
            return;
        }
    }
    // pointer to Doomed Node
    Node* dnode = tlp->next;
    // reassign node.next(n-1) to n+1
    tlp->next = dnode->next;
    free(dnode);

}

// reverse list using recursion
// pass by value Node* head as initial parameter
void reverselist(Node* pointer){
    // exit condition
    if (pointer->next == NULL) {
        head = pointer;
        return;
    }
    // build recursive tree using next Node
    // code will not continue until recursive tree has hit exit condition (return;)
    reverselist(pointer->next);

    /* after recursion has hit exit condition
    // each level of recursive tree will run the following statements
       from right to left */

    // at the top of the stack frame,
    // the prior Node address should be in (*pointer).next
    Node* prior = pointer->next;
    // point prior Node to current pointer
    prior->next = pointer;
    // current pointer should be set to NULL as it pops off the stack frame
    pointer->next = NULL;
} // when process reads this line, the current recursive call will pop off stack frame
  // and go down to the next stack frame, which is the next level down in the recursive tree

void genlistsize() {
    printf("Enter size of linked list\n");
    fflush(stdout);
    int listsize;
    scanf("%d", &listsize);
    for (int i = 0; i < listsize; i++) {
        printf("Enter integer\n");
        fflush(stdout);
        int input;
        scanf("%d", &input);
        // no reassignment to head
        insertf(input);
        printlist();
    }
}

void testcode() {
#if VERSION >=1
    insertn(2, 1);
    insertn(3, 3);
    insertn(4, 1);
    insertn(5, 2);
    insertn(9, 9);
    printlist();
#endif

#if VERSION == 1
    reverselist(head);
    printlist();
    reverselist(head);
    printlist();
#endif

#if VERSION == 2
    deleten(1);
    printlist();
    deleten(5);
    printlist();
    printf("\ndelete 4th\n");
    fflush(stdout);
    deleten(4);
    printlist();
    deleten(2);
    printlist();
#endif
}
