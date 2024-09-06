#include <stdio.h>

#include "helper.h"

typedef struct node {
	int data;
	struct node* next;
} Node;

int main() {
	Node temp = { 0, NULL };
	Node node = { -1, &temp };

	printf("Binary representation of node:\n");
	displayBitPattern(&node, sizeof(node));

	printf("\nBinary representation of temp:\n");
	displayBitPattern(&node.next, sizeof(Node*));

	printf("\nAddress of temp: %p", node.next);

	return 0;
}
