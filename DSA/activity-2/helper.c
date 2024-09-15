#include <stdio.h>
#include <stdlib.h>

#include "helper.h"

void printList(List list) {
	while (list != NULL) {
		printf("%d", list->data);

		if (list->next != NULL) {
			printf(", ");
		}

		list = list->next;
	}

	printf("\n");
}

void initListNoHeader(List *list) { *list = NULL; }

void initListWithHeader(List *list) {
	*list = (Node *)malloc(sizeof(Node));

	if (*list != NULL) {
		(*list)->next = NULL;
	}
}

void insertLastPPN(List *list, int data) {
	if (list != NULL) {
		while (*list != NULL)
			list = &(*list)->next;

		Node *newNode = (Node *)malloc(sizeof(Node));

		if (newNode != NULL) {
			newNode->data = data;
			newNode->next = NULL;

			*list = newNode;
		}
	}
}

void insertLastLookAhead(List list, int data) {
	if (list != NULL) {
		Node *newNode = (Node *)malloc(sizeof(Node));

		if (newNode != NULL) {
			while (list->next != NULL)
				list = list->next;

			newNode->data = data;
			newNode->next = NULL;
			list->next = newNode;
		}
	}
}

void deleteElemPPN(List *list, int elem) {
	if (list != NULL) {
		while (*list != NULL && (*list)->data != elem)
			list = &(*list)->next;

		if (*list != NULL) {
			List temp = *list;
			*list = temp->next;

			free(temp);
		};
	}
}

void deleteElemLookAhead(List list, int elem) {
	while (list != NULL && list->next != NULL && list->next->data != elem)
		list = list->next;

	if (list->next != NULL) {
		List temp = list->next;
		list->next = temp->next;

		free(temp);
	}
}
