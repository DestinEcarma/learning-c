#include "helper.h"

int main() {
	Queue queue;
	initQueue(&queue);

	enqueue(&queue, 1);
	enqueue(&queue, 2);
	enqueue(&queue, 3);
	enqueue(&queue, 4);
	enqueue(&queue, 5);

	printQueue(&queue);

	dequeue(&queue);
	dequeue(&queue);

	printQueue(&queue);

	return 0;
}
