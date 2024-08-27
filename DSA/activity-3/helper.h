#ifndef HELPER_H
#define HELPER_H

typedef struct node {
	int data;
	struct node* next;
} Node, *List;

void printList(List);

Node* createNode(int);

int getMiddleElement(List);

#endif
