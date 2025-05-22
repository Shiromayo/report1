#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

QUEUE_TYPE gQueue[QUEUE_SIZE];
int front = 0;
int count = 0;

void error(char *s) {
    fprintf(stderr, "Error: %s\n", s);
    exit(1);
}

void initQueue(void) { front = count = 0; }

int isQueueEmpty(void) { return count == 0; }

int isQueueFull(void) { return count == QUEUE_SIZE; }

void enqueue(QUEUE_TYPE x) {
    if (isQueueFull())
        error("enqueue: 待ち行列はフル状態です。");
    int rear = (front + count) % QUEUE_SIZE;
    gQueue[rear] = x;
    count++;
}

QUEUE_TYPE dequeue(void) {
    if (isQueueEmpty())
        error("dequeue: 待ち行列は空状態です。");
    QUEUE_TYPE x = gQueue[front];
    front = (front + 1) % QUEUE_SIZE;
    count--;
    return x;
}

void printQueue(void) {
    printf("Queue: ");
    for (int i = 0; i < count; i++) {
        printf("%s ", gQueue[(front + i) % QUEUE_SIZE]);  
    }
    printf("\n");
}