#include <stdbool.h>
#include <stdio.h>

#include "stackArray.h"

void printStack(Stack stack) {
	while (!isEmpty(&stack)) {
		printf("%d", top(&stack));
		pop(&stack);

		if (!isEmpty(&stack)) {
			printf(", ");
		}
	}

	printf("\n");
}

void initialize(Stack *stack) { stack->top = -1; }

void push(Stack *stack, int data) {
	if (!isFull(stack)) {
		stack->elems[++stack->top] = data;
	}
}

void pop(Stack *stack) {
	if (!isEmpty(stack)) {
		stack->top--;
	}
}

int top(Stack *stack) {
	int result = -1;

	if (!isEmpty(stack)) {
		result = stack->elems[stack->top];
	}

	return result;
}

bool isEmpty(Stack *stack) { return stack->top == -1; }

bool isFull(Stack *stack) { return stack->top == MAX - 1; }
