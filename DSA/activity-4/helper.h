#ifndef HELPER_H
#define HELPER_H

#define MAX 10

typedef struct {
	int elems[MAX];
	int count;
} List;

void printList(List *);

void initList(List *);

void insertLast(List *, int);
void insertLastUnique(List *, int);
void insertSorted(List *, int);

void deleteElem(List *, int);
void deleteAllOccur(List *, int);

#endif
