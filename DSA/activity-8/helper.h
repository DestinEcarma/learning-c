#ifndef HELPER_H
#define HELPER_H

#include <stdbool.h>

#define MAX 10

typedef struct {
  int elems[MAX];
  int front;
  int rear;
} Queue;

void printQueue(Queue);

void initQueue(Queue*);
void enqueue(Queue*, int);
void dequeue(Queue*);

int peek(Queue*);

bool isEmpty(Queue*);
bool isFull(Queue*);

#endif
