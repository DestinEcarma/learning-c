#include <stdio.h>

#include "helper.h"

#define SIZE 10

int main() {
	List head = createNode(0);
	List tail = head;
	
	for (int i = 1; i < SIZE; i++) {
		Node* temp = createNode(i);

		tail->next = temp;
		tail = temp;
	}

	printf("List: ");
	printList(head);

	int mid = getMiddleElement(head);

	printf("Middle Element: %d", mid);

	return 0;
}
