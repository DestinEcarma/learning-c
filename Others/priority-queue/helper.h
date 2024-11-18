#ifndef HELPER_H
#define HELPER_H

#include <stdlib.h>

#define MAX 10

typedef struct {
	int lastIdx;
	int list[MAX];
} PriorityQueue;

void initQueue(PriorityQueue *queue);

void minEnqueue(PriorityQueue *queue, int data);
int minDequeue(PriorityQueue *queue);

void maxEnqueue(PriorityQueue *queue, int data);
int maxDequeue(PriorityQueue *queue);

void displayMinQueue(PriorityQueue queue);
void displayMaxQueue(PriorityQueue queue);

#endif
