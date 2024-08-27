#include <stdio.h>
#include <stdlib.h>

#include "helper.h"

void printList(List list) {
	while (list != NULL) {
		printf("%d ", list->data);
		list = list->next;
	}

	printf("\n");
}

// * Function Definition
void insertLast(List* list, int x) {
	// Prevent NULL pointers
	if (list != NULL) {
		// Traverse through the linked list until it
		// reaches the last node, and the new data
		// must not be in the linked list
		while (*list != NULL && (*list)->data != x) list = &((*list)->next);

		// Check if L is the last node
		if (*list == NULL) {
			Node* newNode = (Node*)malloc(sizeof(Node));

			// Check if the allocation was a success
			if (newNode != NULL) {
				newNode->data = x;
				newNode->next = NULL;

				*list = newNode;
			}
		}
	}
}
