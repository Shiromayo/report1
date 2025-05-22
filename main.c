#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib1.h"
#include "stack.h"
#include "queue.h"

int getPriority(char* op) {
    if (strcmp(op, "^") == 0) return 4;
    if (strcmp(op, "*") == 0 || strcmp(op, "/") == 0 || strcmp(op, "%") == 0) return 3;
    if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0) return 2;
    return 0;
}

int isRightAssociative(char* op) {
    return strcmp(op, "^") == 0;
}

void infixToRPN(char* tokens[], int tokenCount) {
    initQueue();
    initStack();

    for (int i = 0; i < tokenCount; i++) {
        char* token = tokens[i];

        if (isNumberStr(token)) {
            enqueue(token);
        } else if (strcmp(token, "(") == 0) {
            push(token);
        } else if (strcmp(token, ")") == 0) {
            while (!isEmpty() && strcmp(peek(), "(") != 0) {
                enqueue(pop());
            }
            pop(); 
        } else if (isOpStr(token)) {
            while (!isEmpty() && getPriority(peek()) >= getPriority(token) 
                   && !(isRightAssociative(token) && getPriority(peek()) == getPriority(token))) {
                enqueue(pop());
            }
            push(token);
        }
    }

    while (!isEmpty()) {
        enqueue(pop());
    }

    while (!isQueueEmpty()) {
        printf("%s ", dequeue());
    }
    printf("\n");
}

int main() {
    char* tokens[100];
    int tokenCount;

    while ((tokenCount = read(tokens, 100)) != -1) {
        infixToRPN(tokens, tokenCount);
    }

    return 0;
}