#ifndef HELPER_H
#define HELPER_H

#define MAX 10

typedef int List;

typedef struct {
	int data;
	int link;
} Node;

typedef struct {
	Node nodes[MAX];
	List avail;
} Cursor;

void printList(Cursor *, List);

void initList(Cursor *);
int allocSpace(Cursor *);
void dealloc(Cursor *, int);
void insertFirst(Cursor *, List *, int);
void insertLast(Cursor *, List *, int);
void insertSorted(Cursor *, List *, int);
void deleteData(Cursor *, List *, int);

#endif
