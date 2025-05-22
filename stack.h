#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 200
typedef char* STACK_TYPE;

extern STACK_TYPE stack[];
extern int top;

void initStack(void); 
void push(STACK_TYPE value);
STACK_TYPE pop(void);
STACK_TYPE peek(void);
int isEmpty(void);
void printStack(void);

#endif