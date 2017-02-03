/*local head version*/
#include <stdio.h>
#include <stdlib.h>

// defining the struct in a recursive manner is allowed in C
typedef struct node {
    int value;
    struct node* next;
} Node;



Node* insert(Node* head, int x);
void reverseprint(Node* pointer);
void printlist(Node* head);

int main() {
    Node* head;
    head = NULL;

    int listsize;

    // test insert
    printf("Enter size of linked list\n");
    fflush(stdout);

    scanf("%d", &listsize);
    for (int i = 0; i < listsize; i++) {
        printf("Enter integer\n");
        fflush(stdout);
        int input;
        scanf("%d", &input);
        // collect return Node* to update local head-Node*
        head = insert(head, input);
        printlist(head);
        printf("\n");
        reverseprint(head);
    }

    // test insertPtr2Ptr
    printf("Enter size of linked list\n");
    fflush(stdout);
    scanf("%d", &listsize);
    for (int i = 0; i < listsize; i++) {
        printf("Enter integer\n");
        fflush(stdout);
        int input;
        scanf("%d", &input);
        // must pass address of pointer to generate
        // pointer-to-address == pointer-to-pointer
        // do not need to return pointer to update local head
        insertPtr2Ptr(&head, input); //pass head-Node* by reference
        printlist(head);
        printf("\n");
        reverseprint(head);
    }

    return (0);
}

Node* insert(Node* head, int x) {
    Node* new = malloc(sizeof (Node));
    new->value = x;
    // assign new Node's pointer to next &Node == head(current)
    // if last Node, will copy NULL from head(current)
    new->next = head;
    // head(updated) now points to new &Node
    head = new;
    // update calling head
    return head;
}

// to use pointer-to-pointer, we need the address of the first pointer
// pointer-of-pointer's value will be address of first pointer
// return-type void can be used since
// pointer-to-pointer can manipulate main's local head pointer
void insertPtr2Ptr(Node** ptr2head, int x) {
    Node* new = malloc(sizeof (Node));
    new->value = x;
    // assign new Node's pointer (next) to &Node-head(current)
    // if last Node, will copy NULL from head(current)
    // dereference pointer-to-pointer to get pointer
    new->next = *ptr2head;
    // head(updated) now points to new &Node
    *ptr2head = new;
}

// pass by value so temp is local, so change is acceptable
// changing a pass by reference variable dereference start of linked list
/*recursive calls implicitly allocates memory for each method calls
this is not necessary for a normal print.
Moving and printing the pointer would be more efficient*/
void printlist(Node* pointer) {
    if (pointer == NULL) { //exit condition
      printf("\n");
      return;
    }
    printf("%d ", pointer->value); // print before recursive call stays in order
    printlist(pointer->next); // recursive call
}

// to print in reverse, something has to be stored in memory so recursion is ok
void reverseprint(Node* pointer) {
    if (pointer == NULL) { //exit condition
      printf("\n");
      return;
    }
    reverseprint(pointer->next); // recursive call
    // print is called for each level of the recursive tree
    //from right to left, which appears on screen in reverse
    printf("%d ", pointer->value);
}
