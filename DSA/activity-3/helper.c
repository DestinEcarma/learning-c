#include <stdio.h>
#include <stdlib.h>

#include "helper.h"

void printList(List list) {
	while (list != NULL) {
		printf("%d", list->data);

		if (list->next != NULL){
			printf(", ");
		}

		list = list->next;
	}

	printf("\n");
}

Node* createNode(int data) {
	Node* node = (Node*)malloc(sizeof(Node));

	if (node != NULL) {
		node->data = data;
		node->next = NULL;
	}

	return node;
}

int getMiddleElement(List L) {
	int result = -1;

	if (L != NULL) {
		List slow = L;
		List fast = L;

		while (fast != NULL && fast->next != NULL) {
			slow = slow->next;
			fast = fast->next->next;
		}

		result = slow->data;
	}

	return result;
}
