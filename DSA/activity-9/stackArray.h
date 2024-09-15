#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include <stdbool.h>

#define MAX 10

typedef struct {
	int elems[MAX];
	int top;
} Stack;

void printStack(Stack);

void initialize(Stack *);
void push(Stack *, int);
void pop(Stack *);
int top(Stack *);
bool isEmpty(Stack *);
bool isFull(Stack *);

#endif
