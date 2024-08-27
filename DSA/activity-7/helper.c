#include <stdio.h>
#include <stdlib.h>

#include "helper.h"

void printQueue(Queue* queue) {
	Node* curr = queue->front;

	while (curr != NULL) {
		printf("%d", curr->data);
		curr = curr->next;

		if (curr != NULL) {
			printf(", ");
		}
	}

	printf("\n");
}

void initQueue(Queue* queue) {
	queue->front = NULL;
	queue->rear = NULL;
}

void enqueue(Queue* queue, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	if (newNode != NULL) {
		newNode->data = data;
		newNode->next = NULL;

		if (queue->front == NULL) {
			queue->front = newNode;
		} else {
			queue->rear->next = newNode;
		}

		queue->rear = newNode;
	}
}

void dequeue(Queue* queue) {
	if (queue->front != NULL) {
		Node* temp = queue->front;
		queue->front = temp->next;

		if (queue->front == NULL) {
			queue->rear = NULL;
		}

		free(temp);
	}
}
