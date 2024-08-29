#include <stdio.h>

#include "helper.h"

void printList(Cursor* cursor, List head) {
	while (head != -1) {
		printf("%d", cursor->nodes[head].data);
		head = cursor->nodes[head].link;

		if (head != -1) {
			printf(", ");
		}
	}

	printf("\n");
}

void initList(Cursor* cursor) {
	cursor->avail = MAX - 1;

	for (int i = 0; i < MAX; i++) {
		cursor->nodes[i].link = i - 1;
	}
}

int allocSpace(Cursor* cursor) {
	int result = cursor->avail;

	if (result != -1) {
		cursor->avail = cursor->nodes[result].link;
	}

	return result;
}

void deallocSpace(Cursor* cursor, int i) {
	if (i >= 0 && i < MAX) {
		cursor->nodes[i].link = cursor->avail;
	    cursor->avail = i;
	}
}

void insertFirst(Cursor* cursor, List* head, int data) {
	int i = allocSpace(cursor);

	if (i != -1) {
		Node* node = cursor->nodes + i;

	    node->data = data;
	    node->link = *head;

	    *head = i;
	}
}

void insertLast(Cursor* cursor, List* head, int data) {
	int i = allocSpace(cursor);

	if (i != -1) {
		Node* node = cursor->nodes + i;

		while (*head != -1) {
			head = &cursor->nodes[*head].link;
		}

		node->data = data;
		node->link = -1;
		*head = i;
	}
}

void insertSorted(Cursor* cursor, List* head, int data) {
	int i = allocSpace(cursor);

	if (i != -1) {
		Node* node = cursor->nodes + i;

		while (*head != -1 && cursor->nodes[*head].data < data) {
			head = &cursor->nodes[*head].link;
		}

		node->data = data;
		node->link = *head;
		*head = i;
	}
}

void deleteData(Cursor* cursor, List* head, int data) {
	if (*head != -1) {
		Node* curr = cursor->nodes + *head;

		while (curr->link != -1 && curr->data != data) {
			head = &curr->link;
			curr = cursor->nodes + *head;
		}

		if (curr->data == data) {
			int temp = curr->link;
			deallocSpace(cursor, *head);
			*head = temp;
		}
	}
}
