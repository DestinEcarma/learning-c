#include <stdio.h>

#include "helper.h"

int main() {
	PriorityQueue minQueue;

	initQueue(&minQueue);

	minEnqueue(&minQueue, 1);
	minEnqueue(&minQueue, 3);
	minEnqueue(&minQueue, 2);
	minEnqueue(&minQueue, 4);
	minEnqueue(&minQueue, 6);
	minEnqueue(&minQueue, 5);

	printf("Min Dequeue Order: ");
	displayMinQueue(minQueue);

	PriorityQueue maxQueue;

	initQueue(&maxQueue);

	maxEnqueue(&maxQueue, 4);
	maxEnqueue(&maxQueue, 3);
	maxEnqueue(&maxQueue, 6);
	maxEnqueue(&maxQueue, 8);
	maxEnqueue(&maxQueue, 9);
	maxEnqueue(&maxQueue, 2);

	printf("\nMax Dequeue Order: ");
	displayMaxQueue(maxQueue);

	return 0;
}
