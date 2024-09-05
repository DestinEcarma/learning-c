#ifndef HELPER_H
#define HELPER_H

#include <stdbool.h>

#define MAX 10

typedef char Set[MAX];

void printSet(Set*);

void zeroSet(Set*);
void insertSet(Set*, int);
void removeSet(Set*, int);
Set* unionSet(Set*, Set*);
Set* intersectionSet(Set*, Set*);
Set* differenceSet(Set*, Set*);
Set* complementSet(Set*);

bool isEqualSetSortedTest(Set*, Set*);

#endif
