#include "runner.h"

/*#include "stackArray.h"*/
#include "stackLinkedList.h"

void runner() {
	Stack stack;
	initialize(&stack);

	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);
	push(&stack, 4);
	push(&stack, 5);

	printStack(stack);

	while (!isEmpty(&stack)) {
		pop(&stack);
		printStack(stack);
	}
}
