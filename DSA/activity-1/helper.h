#ifndef HELPER_H
#define HELPER_H

typedef struct node {
	int data;
	struct node *next;
} Node, *List;

void printList(List);

// Function Header
void insertLast(List *, int);

#endif
