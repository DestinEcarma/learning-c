#include <stdio.h>
#include <stdbool.h>

#include "helper.h"

void printQueue(Queue queue) {
	while (isEmpty(&queue) == false) {
		printf("%d ", peek(&queue));
		dequeue(&queue);
	}

	printf("\n");
}

void initQueue(Queue* queue) {
	queue->front = 1;
	queue->rear = 0;
}

void enqueue(Queue* queue, int data) {
	if (isFull(queue) == false) {
		queue->rear = (queue->rear + 1) % MAX;
		queue->elems[queue->rear] = data;	
	}
}

void dequeue(Queue* queue) {
	if (isEmpty(queue) == false) {
		queue->front = (queue->front + 1) % MAX;
	}
}

int peek(Queue* queue) {
	if (isEmpty(queue) == false) {
		return queue->elems[queue->front];
	}

	return -1;
}

bool isEmpty(Queue* queue) {
	return queue->front == (queue->rear + 1) % MAX;
}

bool isFull(Queue* queue) {
	return queue->front == (queue->rear + 2) % MAX;
}
