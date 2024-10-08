#include <stdio.h>
#include <stdlib.h>

#include "helper.h"

void printSet(Set set) {
	for (Node *curr = set; curr != NULL; curr = curr->next) {
		printf("%d", curr->data);

		if (curr->next != NULL) {
			printf(", ");
		}
	}

	printf("\n");
}

void initSet(Set *set) {
	*set = NULL;
}

void insertFirst(Set *set, int data) {
	Node *trav = *set;

	while (trav != NULL && trav->data != data) {
		trav = trav->next;
	}

	if (trav == NULL) {
		Node *newNode = (Node *)malloc(sizeof(Node));

		if (newNode != NULL) {
			newNode->data = data;
			newNode->next = *set;
			*set = newNode;
		}
	}
}

void insertLast(Set *set, int data) {
	while (*set != NULL && (*set)->data != data) {
		set = &(*set)->next;
	}

	if (*set == NULL) {
		Node *newNode = (Node *)malloc(sizeof(Node));

		if (newNode != NULL) {
			newNode->data = data;
			newNode->next = NULL;
			*set = newNode;
		}
	}
}

void insertSorted(Set *set, int data) {
	while (*set != NULL && (*set)->data < data) {
		set = &(*set)->next;
	}

	if (*set == NULL || (*set)->data != data) {
		Node *newNode = (Node *)malloc(sizeof(Node));

		if (newNode != NULL) {
			newNode->data = data;
			newNode->next = *set;
			*set = newNode;
		}
	}
}

void deleteFirst(Set *set) {
	if (*set != NULL) {
		Node *temp = *set;
		*set = (*set)->next;
		free(temp);
	}
}

void deleteLast(Set *set) {
	if (*set != NULL) {
		while ((*set)->next != NULL) {
			set = &(*set)->next;
		}

		Node *temp = *set;
		*set = NULL;
		free(temp);
	}
}

void deleteData(Set *set, int data) {
	while (*set != NULL && (*set)->data != data) {
		set = &(*set)->next;
	}

	if (*set != NULL) {
		Node *temp = *set;
		*set = (*set)->next;
		free(temp);
	}
}

void makeNull(Set *set) {
	while (*set != NULL) {
		deleteFirst(set);
	}
}

bool isEqualSetSortedTest(Set A, Set B) {
	while (A != NULL && B != NULL && A->data == B->data) {
		A = A->next;
		B = B->next;
	}

	return A == NULL && B == NULL;
}

bool isEqualSetUnsortedTest(Set A, Set B) {
	bool result = true;

	Node *outerA = A;
	Node *outerB = B;

	while (outerA != NULL && outerB != NULL && result) {
		Node *innerA = A;
		Node *innerB = B;

		while (innerA != NULL && outerB->data != innerA->data) {
			innerA = innerA->next;
		}

		while (innerB != NULL && outerA->data != innerB->data) {
			innerB = innerB->next;
		}

		result = innerA != NULL && innerB != NULL;
		outerA = outerA->next;
		outerB = outerB->next;
	}

	return result;
}
