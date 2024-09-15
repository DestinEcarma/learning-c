#include <stdio.h>
#include <stdlib.h>

#include "helper.h"

void displaySet(Set set) {
	while (set != NULL) {
		printf("%d", set->data);
		set = set->next;

		if (set != NULL) {
			printf(", ");
		}
	}

	printf("\n");
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

Set unionSetOrderedTest(Set A, Set B) {
	Set result = NULL;
	Set *tail = &result;

	int previousData = (A->data < B->data) ? A->data - 1 : B->data - 1;

	while (A != NULL && B != NULL) {
		int data;
		Set *curr;

		if (A->data < B->data) {
			data = A->data;
			curr = &A;
		} else {
			data = B->data;
			curr = &B;
		}

		Node *temp = (Node *)malloc(sizeof(Node));

		if (temp != NULL && previousData != data) {
			temp->data = data;
			temp->next = NULL;

			*tail = temp;
			tail = &temp->next;
		}

		if (A->data == B->data) {
			A = A->next;
		}

		previousData = data;
		*curr = (*curr)->next;
	}

	Set rest = (A != NULL) ? A : B;

	while (rest != NULL) {
		Node *temp = (Node *)malloc(sizeof(Node));

		if (temp != NULL && previousData != rest->data) {
			temp->data = rest->data;
			temp->next = NULL;

			*tail = temp;
			tail = &temp->next;
		}

		previousData = rest->data;
		rest = rest->next;
	}

	return result;
}

Set unionSetUnorderedTest(Set A, Set B) {
	Set result = NULL;
	Set *tail = &result;

	// Not the most efficient method in terms of space.
	// Time complixity $O(N)$.
	unsigned char set[MAX_INT_UNORDERED_TEST] = {};

	while (A != NULL) {
		Node *temp = (Node *)malloc(sizeof(Node));

		int setIndex = A->data / 8;
		int setPlacement = A->data % 8;

		if (temp != NULL && (set[setIndex] >> setPlacement & 1) == 0) {
			temp->data = A->data;
			temp->next = NULL;

			*tail = temp;
			tail = &temp->next;

			set[setIndex] |= 1 << setPlacement;
		}

		A = A->next;
	}

	while (B != NULL) {
		Node *temp = (Node *)malloc(sizeof(Node));

		int setIndex = B->data / 8;
		int setPlacement = B->data % 8;

		if (temp != NULL && (set[setIndex] >> setPlacement & 1) == 0) {
			temp->data = B->data;
			temp->next = NULL;

			*tail = temp;
			tail = &temp->next;

			set[setIndex] |= 1 << setPlacement;
		}

		B = B->next;
	}

	return result;
}
