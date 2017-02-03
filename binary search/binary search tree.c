#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

typedef enum {
    false, true
} bool;

typedef struct bst {
    int data;
    struct bst* left;
    struct bst* right;
} Bst;

typedef struct {
    Bst* node;
    struct bstQ* next;
} bstQ;

Bst* newbst(int data);
Bst* insert(Bst* node, int input);
bool search(Bst* node, int input);
Bst* findNode(Bst* node, int input);
int findMinIt(Bst* node);
int findMaxIt(Bst* node);
Bst* findMaxNodeIt(Bst* node);
int findMinRe(Bst* node);
int findMaxRe(Bst* node);
int findHeight(Bst* node);
void queueTreeLevel(Bst* node);
bstQ* newQueue(Bst* current);
void printQ();
void readOnlyPrintQ();
void preorder(Bst* root);
void inorder(Bst* root);
void postorder(Bst* root);
bool isBSTinorder(Bst* root);
bool isBSTutil(Bst* node, int min, int max);
Bst* delete(Bst* node, int n);
int getNext(Bst* node, int n);
int getPrev(Bst* node, int n);
void test();

Bst* root;
bstQ* head;
bstQ* rear;

int main() {
    root = NULL;
    head = NULL;
    rear = NULL;
    test();
    return (0);
}

Bst* newbst(int data) {
    Bst* new = malloc(sizeof (Bst));
    new->data = data;
    new->left = new->right = NULL;
    return new;
}

Bst* insert(Bst* node, int input) {
    // either assign bst* root here or pass it back on first call
    // Bst* node is a local variable(pass by value)
    // so changes to node isn't applied to Bst* root
    //    if (root == NULL) {
    //        root = newbst(input);
    //        return root;
    //    }
    if (node == NULL) {
        node = newbst(input);
    }// when traversing the binary tree,
        // each level will return the same value as before
        // and overwrite the pointers with the same data as before
        // this might prevent dangling pointer bugs
    else if (input <= node->data)
        node->left = insert(node->left, input);
    else if (node->data <= input)
        node->right = insert(node->right, input);
    return node;
}

bool search(Bst* node, int input) {
    if (node == NULL)
        return false;
    else if (node->data == input)
        return true;
    else if (node->data > input)
        return search(node->left, input);
    else if (node->data < input)
        return search(node->right, input);
}

Bst* findNode(Bst* node, int input) {
    if (node == NULL)
        return node;
    else if (node->data == input)
        return node;
    else if (node->data > input)
        return findNode(node->left, input);
    else if (node->data < input)
        return findNode(node->right, input);
}

// pointer is pass by value so modifying it won't change root
int findMinIt(Bst* node) {
    if (node == NULL)
        return -1;
    while (node->left != NULL)
        node = node->left;
    return node->data;
}

int findMaxIt(Bst* node) {
    if (node == NULL)
        return -1;
    while (node->right != NULL)
        node = node->right;
    return node->data;
}

Bst* findMaxNodeIt(Bst* node) {
    if (node == NULL)
        return -1;
    // keep traversing right to find max
    while (node->right != NULL)
        node = node->right;
    return node;
}

int findMinRe(Bst* node) {
    if (node == NULL)
        return -1;
    else if (node->left == NULL)
        return node->data;
    return findMinRe(node->left);
}

int findMaxRe(Bst* node) {
    if (node == NULL)
        return -1;
    else if (node->right == NULL)
        return node->data;
    return findMaxRe(node->right);
}

int findHeight(Bst* node) {
    if (node == NULL)
        // -1 + 1 == 0 since NULL nodes should not be counted
        // convention states height of empty tree is -1
        return -1;
    // +1 for each height, counting only the max
    return max(findHeight(node->left),
            findHeight(node->right)) + 1;
}

void queueTreeLevel(Bst* node) {
    if (node == NULL)
        return;
    // initialize queue if empty
    if (head == NULL
            && rear == NULL) {
        bstQ* new = newQueue(node);
        head = rear = new;
        return;
    }
    // grow queue as head is popped off
    if (node->left != NULL) {
        bstQ* left = newQueue(node->left);
        rear->next = left;
        rear = left;
    }
    if (node->right != NULL) {
        bstQ* right = newQueue(node->right);
        rear->next = right;
        rear = right;
    }
}

// returns pointer so & not needed in assignment
bstQ* newQueue(Bst* current) {
    bstQ* new = malloc(sizeof (bstQ));
    new->node = current;
    new->next = NULL;
    return new;
}

void printQ() {
    if (head == NULL) {
        printf("\nQueue is empty");
        return;
    }
    printf("\nLeveled Queue: ");
    bstQ* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->node->data);
        // as nodes are pull out of queue
        // their left + right nodes are read into the queue
        // if only reading + writing, space complexity is O(n)
        queueTreeLevel(temp->node);
        // if delete queue as it is read will give best space-complexity of O(1)
        // for worst and average space-complexity,
        // at most an entire level will be in the queue
        bstQ* doomed = temp;
        temp = temp->next;
        // increment head of queue
        head = temp;
        // remove from memory
        free(doomed);
    }

}

// not removing queue will present bugs as the queue keeps growing

void readOnlyPrintQ() {
    if (head == NULL) {
        printf("\nQueue is empty");
        return;
    }
    printf("\nLeveled Queue: ");
    bstQ* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->node->data);
        queueTreeLevel(temp->node);
        temp = temp->next;
    }
}

void preorder(Bst* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// traversal of in-order binary search tree
// will yield elements of the tree in sorted order

void inorder(Bst* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(Bst* root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

bool isBSTinorder(Bst* root) {
    // static variable maintain value over repeated function calls
    static Bst* prev = NULL;

    // traverse the tree in inorder fashion and keep track of prev node
    if (root) {
        // check left
        if (!isBSTinorder(root->left))
            return false;
        //compare data to prev
        if (prev != NULL &&
                prev->data >= root->data)
            return false;
        // advance prev pointer
        prev = root;
        //check right
        return isBSTinorder(root->right);
    }
    return true;
}

// recursive check
// time-complexity: O(n)
// Auxiliary Space : O(1) if Function Call Stack size is not considered, otherwise O(n)

bool isBSTutil(Bst* node, int min, int max) {
    // an empty tree is BST
    if (node == NULL)
        return true;
    // false if violates min/max constraint
    if (node->data <= min)
        return false;
    if (node->data >= max)
        return false;
    // otherwise check subtrees recursively,
    // tightening the min/max constraint
        return
            isBSTutil(node->left, min, node->data - 1) &&
            isBSTutil(node->right, node->data + 1, max);
    /* alternative way to run multiple recursion
    if(!isBSTutil(node->left, min, node->data - 1))
        return false;
    return isBSTutil(node->right, node->data + 1, max); */
}

// must return node for recursion to work
Bst* delete(Bst* node, int n) {
    if(node == NULL) // base/exit condition
        return node; // == return NULL;
    // recursively search left node for smaller n
    else if( n < node->data)
        node->left = delete(node->left, n); // run delete on left-node
    // recursively search right node for greater n
    else if (n > node->data)
        node->right = delete(node->right, n); // run delete on right-node
    // node located
    else if (n == node->data) {
        // if leaf node
        if(node->left == NULL && node->right == NULL) {
            free(node);
            node = NULL;
        }
        // if single child
        else if(node->left == NULL) {
            Bst* temp = node;
            node = node->right; // replace current node with only child
            free(temp); // reclaim memory from deleted node
        }
        else if(node->right == NULL){
            Bst* temp = node;
            node = node->left; // replace current node with only child
            free(temp); // reclaim memory from deleted node
        }
        // if two child
        // either replace with greatest value of left BST or
        // lowest value of right BST
        else {
            Bst* temp = findMaxNodeIt(node->left);
            node->data = temp->data;
            // send temp node to deletion so
            // it returns NULL to prior-node's next-pointer
            // if we just free node here,
            // pointer to freed note will point to garbage data
            node->left = delete(node->left, temp->data);
        }
    }
    return node;
}

int getNext(Bst* node, int n){
    if(node==NULL)
        return -1;
    if(!search(node, n))
        return -1;
    else if(node->data == n)
        return findMinIt(node->right);
    else if(node->data < n)
        return getNext(node->right, n);
    Bst* ancestor;
    while (n < node->data) {
        // can't use recursion since static ancestor can present bugs
        ancestor = node;
        node = node->left;
    }
    while( node->data < n) {
        if(node== NULL)
            return -1;
        node = node->right;
    }
    // valid right node contains next data
    if(node->data == n && node->right != NULL) {
        node = node->right;
        return node->data;
    }
    // right node is NULL, return ancestor
    if(node->data == n && node->right == NULL)
        return ancestor->data;
}
// function to find in-order predecessor in a BST
int getPrev(Bst* node, int n){
    // find the node - O(h)
    Bst* current = findNode(node, n);
    if(current == NULL)
        return -1;
    if(current->left != NULL) // node has left subtree
        return findMaxIt(current->left); // O(h)
    else { // no left subtree
        // find closest ancestor that is a left-subtree
        Bst* predecessor = NULL;
        Bst* ancestor = root;
        // walk the tree up to before current node
        while(ancestor != current) {
            // keep ancestor lower than current
            if(ancestor->data < current->data) {
                // save lower node to predecessor
                predecessor = ancestor; // deepest node for which current node is left
                ancestor = ancestor->right;
            } else
                // if ancestor data is greater,
                // must go down left node to decrease value
                ancestor = ancestor->left;
        }
        if(predecessor == NULL)
            return -1;
        else
            return predecessor->data;

    }
}

void test() {
    // pass initial bst* back to bst* root for assignment
    root = insert(root, 20);
    // subsequent returns to root
    // are not necessary as value returned will be the same
    insert(root, 10);
    insert(root, 15);
    insert(root, 25);
    insert(root, 30);
    insert(root, 35);

    bool res;
    int n;
    res = search(root, n = 15);
    if (res == true)
        printf("found %d\n", n);
    else
        printf("%d not found\n", n);
    n = findMinIt(root);
    printf("\nminimum = %d", n);
    n = findMaxIt(root);
    printf("\nmaximum = %d", n);

    n = findMinRe(root);
    printf("\nminimum = %d", n);
    n = findMaxRe(root);
    printf("\nmaximum = %d", n);

    n = findHeight(root);
    printf("\nHeight = %d", n);

    // initialize queue
    queueTreeLevel(root);
    printQ();
    printQ();

    printf("\n");
    preorder(root);
    printf("\n");
    inorder(root);
//    delete(root, 20);
    printf("\n");
    postorder(root);

//    n = getNext(root, 35);
//    printf("\nNext = %d", n);
    n = getPrev(root, 35);
    printf("\nPrev = %d", n);

    res = isBSTinorder(root);
    if (res)
        printf("\nBST true");
    else
        printf("\nBST false");

    res = isBSTutil(root, INT_MIN, INT_MAX);
    if (res)
        printf("\nBST true");
    else
        printf("\nBST false");

}
