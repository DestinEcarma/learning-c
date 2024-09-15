#ifndef HELPER_H
#define HELPER_H

typedef struct node {
	int data;
	struct node *next;
} Node, *List;

void printList(List);

void initListNoHeader(List *);
void initListWithHeader(List *);

void insertLastPPN(List *, int);
void insertLastLookAhead(List, int);

void deleteElemPPN(List *, int);
void deleteElemLookAhead(List, int);

#endif
