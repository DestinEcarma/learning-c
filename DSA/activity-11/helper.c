#include <stdio.h>

#include "helper.h"

void printList(Cursor *cursor, List head) {
	while (head != -1) {
		printf("%d", cursor->nodes[head].data);
		head = cursor->nodes[head].link;

		if (head != -1) {
			printf(", ");
		}
	}

	printf("\n");
}

void initList(Cursor *cursor) {
	cursor->avail = MAX - 1;

	for (int i = 0; i < MAX; i++) {
		cursor->nodes[i].link = i - 1;
	}
}

int allocSpace(Cursor *cursor) {
	int result = cursor->avail;

	if (result != -1) {
		cursor->avail = cursor->nodes[result].link;
	}

	return result;
}

void deallocSpace(Cursor *cursor, int i) {
	if (i >= 0 && i < MAX) {
		cursor->nodes[i].link = cursor->avail;
		cursor->avail = i;
	}
}

void insertFirst(Cursor *cursor, List *head, int data) {
	int i = allocSpace(cursor);

	if (i != -1) {
		Node *node = cursor->nodes + i;

		node->data = data;
		node->link = *head;

		*head = i;
	}
}

void deleteFirst(Cursor *cursor, List *head) {
	if (*head != -1) {
		int i = *head;
		*head = cursor->nodes[*head].link;
		deallocSpace(cursor, i);
	}
}

void insertSorted(Cursor *cursor, List *head, int data) {
	int i = allocSpace(cursor);

	if (i != -1) {
		Node *node = cursor->nodes + i;

		while (*head != -1 && cursor->nodes[*head].data < data) {
			head = &cursor->nodes[*head].link;
		}

		node->data = data;
		node->link = *head;
		*head = i;
	}
}

boolean isEqualListOrderedTest(Cursor *cursor, List A, List B) {
	while (A != -1 && B != -1 &&
		   cursor->nodes[A].data == cursor->nodes[B].data) {

		A = cursor->nodes[A].link;
		B = cursor->nodes[B].link;
	}

	return (A == -1 && B == -1) ? TRUE : FALSE;
}

boolean isEqualListUnorderedTest(Cursor cursor, List A, List B) {
	List *trav = &B;

	while (A != -1 && *trav != -1) {
		while (*trav != -1 &&
			   cursor.nodes[A].data != cursor.nodes[*trav].data) {
			trav = &cursor.nodes[*trav].link;
		}

		if (*trav != -1) {
			deleteFirst(&cursor, trav);
			trav = &B;
		}

		A = cursor.nodes[A].link;
	}

	return (A == -1 && B == -1) ? TRUE : FALSE;
}
