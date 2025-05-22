#ifndef QUEUE_H
#define QUEUE_H

#define QUEUE_SIZE 200 

typedef char* QUEUE_TYPE;

extern QUEUE_TYPE gQueue[];
extern int front;
extern int count;

void error(char *s);
void initQueue(void);
int isQueueEmpty(void);
int isQueueFull(void);
void enqueue(QUEUE_TYPE x);
QUEUE_TYPE dequeue(void);
void printQueue(void);

#endif