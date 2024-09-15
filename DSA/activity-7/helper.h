#ifndef HELPER_H
#define HELPER_H

typedef struct node {
	int data;
	struct node *next;
} Node;

typedef struct {
	Node *front;
	Node *rear;
} Queue;

void printQueue(Queue *);

void initQueue(Queue *);
void enqueue(Queue *, int);
void dequeue(Queue *);

#endif
