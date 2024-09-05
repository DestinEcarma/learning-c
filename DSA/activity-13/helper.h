#ifndef HELPER_H
#define HELPER_H

#include <stdbool.h>

typedef struct node {
	int data;
	struct node *next;
} Node, *Set;

void printSet(Set);

void initSet(Set*);
void insertFirst(Set*, int);
void insertLast(Set*, int);
void insertSorted(Set*, int);

void deleteFirst(Set*);
void deleteLast(Set*);
void deleteData(Set*, int);
void makeNull(Set*);

int lengthSet(Set);

bool isEqualSetSortedTest(Set, Set);
bool isEqualSetUnsortedTest(Set, Set);

#endif
