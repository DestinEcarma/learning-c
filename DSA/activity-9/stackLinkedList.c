#include <stdio.h>
#include <stdlib.h>

#include "stackLinkedList.h"

void printStack(Stack stack) {
	Stack temp;

	initialize(&temp);

	while (!isEmpty(&stack)) {
		int data = top(&stack);

		printf("%d", data);
		push(&temp, data);
		pop(&stack);

		if (!isEmpty(&stack)) {
			printf(", ");
		}
	}

	while (!isEmpty(&temp)) {
		push(&stack, top(&temp));
		pop(&temp);
	}

	printf("\n");
}

void initialize(Stack *stack) { *stack = NULL; }

void push(Stack *stack, int data) {
	Node *newNode = (Node *)malloc(sizeof(Node));

	if (newNode != NULL) {
		newNode->data = data;
		newNode->next = *stack;
		*stack = newNode;
	}
}

void pop(Stack *stack) {
	if (isEmpty(stack) == false) {
		Node *temp = *stack;
		*stack = temp->next;
		free(temp);
	}
}

int top(Stack *stack) {
	int result = -1;

	if (isEmpty(stack) == false) {
		result = (*stack)->data;
	}

	return result;
}

bool isEmpty(Stack *stack) { return *stack == NULL; }

bool isFull(Stack *) { return false; }
