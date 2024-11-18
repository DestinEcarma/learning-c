#include <stdio.h>

#include "helper.h"

int getMinChild(PriorityQueue *queue, int parent) {
	int leftChild = parent * 2 + 1;
	int rightChild = leftChild + 1;

	return queue->list[leftChild] < queue->list[rightChild] ? leftChild
															: rightChild;
}

int getMaxChild(PriorityQueue *queue, int parent) {
	int leftChild = parent * 2 + 1;
	int rightChild = leftChild + 1;

	return queue->list[leftChild] > queue->list[rightChild] ? leftChild
															: rightChild;
}

void initQueue(PriorityQueue *queue) {
	queue->lastIdx = -1;
}

void minEnqueue(PriorityQueue *queue, int data) {
	if (queue->lastIdx + 1 < MAX) {
		int child = ++queue->lastIdx;
		int parent = (child - 1) / 2;

		while (child > 0 && queue->list[parent] > data) {
			queue->list[child] = queue->list[parent];

			child = parent;
			parent = (child - 1) / 2;
		}

		queue->list[child] = data;
	}
}

int minDequeue(PriorityQueue *queue) {
	int temp = -1;

	if (queue->lastIdx >= 0) {
		temp = queue->list[0];

		int data = queue->list[queue->lastIdx--];

		int parent = 0;
		int child = getMinChild(queue, parent);

		while (child <= queue->lastIdx && queue->list[child] < data) {
			queue->list[parent] = queue->list[child];

			parent = child;
			child = getMinChild(queue, parent);
		}

		queue->list[parent] = data;
	}

	return temp;
}

void maxEnqueue(PriorityQueue *queue, int data) {
	if (queue->lastIdx + 1 < MAX) {
		int child = ++queue->lastIdx;
		int parent = (child - 1) / 2;

		while (child > 0 && queue->list[parent] < data) {
			queue->list[child] = queue->list[parent];

			child = parent;
			parent = (child - 1) / 2;
		}

		queue->list[child] = data;
	}
}

int maxDequeue(PriorityQueue *queue) {
	int temp = -1;

	if (queue->lastIdx >= 0) {
		temp = queue->list[0];

		int data = queue->list[queue->lastIdx--];

		int parent = 0;
		int child = getMaxChild(queue, parent);

		while (child <= queue->lastIdx && queue->list[child] > data) {
			queue->list[parent] = queue->list[child];

			parent = child;
			child = getMaxChild(queue, parent);
		}

		queue->list[parent] = data;
	}

	return temp;
}

void displayMinQueue(PriorityQueue queue) {
	for (int data = minDequeue(&queue); data != -1; data = minDequeue(&queue)) {
		printf("%d ", data);
	}

	printf("\n");
}

void displayMaxQueue(PriorityQueue queue) {
	for (int data = maxDequeue(&queue); data != -1; data = maxDequeue(&queue)) {
		printf("%d ", data);
	}

	printf("\n");
}
