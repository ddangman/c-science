// Operator supported: +,-,*,/,%,^,(,)
// Operands supported: all single character operands

#include<stdio.h>
#include<ctype.h>
#include <stdlib.h>

#define MAX 50

typedef struct stack {
    int data[MAX]; // stack as array
    int top; // position of top of stack
} stack;

// forward declaration
int precedence(char);
void init(stack *);
int empty(stack *);
int full(stack *);
int pop(stack *);
void push(stack *, int);
int top(stack *); //value of the top element
void infix_to_postfix(char infix[], char postfix[]);

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter an infix expression(eg: 5+2*4): ");
    fgets(infix, MAX, stdin);
    infix_to_postfix(infix, postfix);
    printf("\nPostfix expression: %s", postfix);
    return 0;
}

void infix_to_postfix(char infix[], char postfix[]) {
    stack s;
    char x, token;
    int i, j; //i-index of infix,j-index of postfix
    init(&s);
    j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        token = infix[i];
        // removes whitespace from input
        if (isspace(token)) {
            continue;
        }
        // numbers go directly to output
        if (isalnum(token))
            postfix[j++] = token;
        // splitting 'else if' for readability    
        else
            if (token == '(')
            push(&s, '('); // open parenthesis goes directly to stack
        else
            if (token == ')')
            //pop operators off stack until opening parenthesis
            while ((x = pop(&s)) != '(')
                postfix[j++] = x;
        else {
            // add space before operator
            postfix[j++] = ' ';
            // repeatedly pop operators off stack if precedence is
            // greater than or equal to encountered operator
            while (precedence(token) <= precedence(top(&s))
                    &&!empty(&s)) { // check if stack is empty
                x = pop(&s);
                postfix[j++] = x;
                // add space before operator
                postfix[j++] = ' ';
            }
            push(&s, token);
        }
    }

    while (!empty(&s)) {
        //add space to remainder of stack operators
        postfix[j++] = ' ';
        x = pop(&s);
        postfix[j++] = x;
    }

    postfix[j] = '\0';
}

int precedence(char x) {
    if (x == '(')
        return (0);
    if (x == '+' || x == '-')
        return (1);
    if (x == '*' || x == '/' || x == '%')
        return (2);

    return (3);
}
// initialize empty stack->top == -1

void init(stack *s) {
    s->top = -1;
}
// return TRUE if top of stack is -1
int empty(stack *s) {
    if (s->top == -1)
        return (1);

    return (0);
}
// check if array is full
// not really necessary since fgets limits input
int full(stack *s) {
    if (s->top == MAX - 1)
        return (1);

    return (0);
}

void push(stack *s, int x) {
    // increment top of stack array
    s->top = s->top + 1;
    // push data to top of stack
    s->data[s->top] = x;
}
// return top of stack
int pop(stack *s) {
    // read top of stack
    int x;
    x = s->data[s->top];
    // decrement stack pointer
    // no need to clear data since
    // anything pushed onto stack will overwrite previous data
    s->top = s->top - 1;
    return (x);
}
// return data on top of stack
int top(stack *p) {
    return (p->data[p->top]);
}
