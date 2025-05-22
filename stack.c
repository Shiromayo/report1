#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

STACK_TYPE stack[MAX_SIZE];
int top = -1;

void initStack(void) {
    top = -1; 
}

void push(STACK_TYPE value) {
    if (top >= MAX_SIZE - 1) {
        fprintf(stderr, "Stack overflow\n");
        exit(1);
    }
    stack[++top] = strdup(value); 
}

STACK_TYPE pop(void) {
    if (top == -1) {
        fprintf(stderr, "Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

STACK_TYPE peek(void) {
    return top >= 0 ? stack[top] : NULL;
}

int isEmpty(void) {
    return top == -1;
}

void printStack(void) {
    printf("Stack: ");
    for (int i = 0; i <= top; i++) {
        printf("%s ", stack[i]);
    }
    printf("\n");
}
