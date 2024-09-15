#ifndef STACK_LINKED_LIST_H
#define STACK_LINKED_LIST_H

#include <stdbool.h>

typedef struct node {
	int data;
	struct node *next;
} Node, *Stack;

void printStack(Stack);

void initialize(Stack *);
void push(Stack *, int);
void pop(Stack *);
int top(Stack *);
bool isEmpty(Stack *);
bool isFull(Stack *);

#endif
