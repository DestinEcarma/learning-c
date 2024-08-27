#include "helper.h"

int main() {
	Queue queue;
	initQueue(&queue);

	enqueue(&queue, 1);
	enqueue(&queue, 2);
	enqueue(&queue, 3);
	enqueue(&queue, 4);
	dequeue(&queue);
	enqueue(&queue, 5);
	enqueue(&queue, 6);
	enqueue(&queue, 7);
	enqueue(&queue, 8);
	enqueue(&queue, 9);
	enqueue(&queue, 10);
	dequeue(&queue);
	enqueue(&queue, 11);

	printQueue(queue);

	while (isEmpty(&queue) == false) {
		dequeue(&queue);
		printQueue(queue);
	}

	return 0;
}
