#include <stdio.h>
#include <stdlib.h>

#include "helper.h"

void printSet(Set set) {
	for (Node* curr = set; curr != NULL; curr = curr->next) {
		printf("%d", curr->data);

		if (curr->next != NULL) {
			printf(", ");
		}
	}

	printf("\n");
}

void initSet(Set* set) {
	*set = NULL;
}

void insertFirst(Set* set, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	if (newNode != NULL) {
		Node* curr = *set;

		while (curr != NULL && curr->data != data) {
			curr = curr->next;
		}

		if (curr == NULL) {
			newNode->data = data;
			newNode->next = *set;
			*set = newNode;
		}
	}
}

void insertLast(Set* set, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	if (newNode != NULL) {
		while (*set != NULL && (*set)->data != data) {
			set = &(*set)->next;
		}

		if (*set == NULL) {
			newNode->data = data;
			newNode->next = NULL;
			*set = newNode;
		}
	}
}

void insertSorted(Set* set, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	if (newNode != NULL) {
		while (*set != NULL && (*set)->data < data) {
			set = &(*set)->next;
		}

		if (*set == NULL || (*set)->data != data) {
			newNode->data = data;
			newNode->next = *set;
			*set = newNode;
		}
	}
}

void deleteFirst(Set* set) {
	if (*set != NULL) {
		Node* temp = *set;
		*set = (*set)->next;
		free(temp);
	}
}

void deleteLast(Set* set) {
	if (*set != NULL) {
		while ((*set)->next != NULL) {
			set = &(*set)->next;
		}

		Node* temp = *set;
		*set = NULL;
		free(temp);
	}
}

void deleteData(Set* set, int data) {
	while (*set != NULL && (*set)->data != data) {
		set = &(*set)->next;
	}

	if (*set != NULL) {
		Node* temp = *set;
		*set = (*set)->next;
		free(temp);
	}
}

void makeNull(Set* set) {
	while (*set != NULL) {
		deleteFirst(set);
	}
}

int lengthSet(Set set) {
	int length = 0;

	for (Node* curr = set; curr != NULL; curr = curr->next) {
		length++;
	}

	return length;
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

	int lengthA = lengthSet(A);	
	int lengthB = lengthSet(B);

	if (lengthA != lengthB) {
		result = false;
	} else {
		Node* outer = (lengthA > lengthB) ? A : B;
		Node* inner = (lengthA > lengthB) ? B : A;

		while (outer != NULL && result) {
			Node* trav = inner;

			while (trav != NULL && outer->data != inner->data) {
				trav = trav->next;
			}

			result = inner != NULL;
			outer = outer->next;
		}
	}

	return result;
}
