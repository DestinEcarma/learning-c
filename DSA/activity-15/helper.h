#ifndef HELPER_H
#define HELPER_H

// Change the value depending on how big
// the number will be, if the number is
// 1024 then this means we need at least
// 128 bytes, the formula is simple
// $size = N / 8$ rounded up, where $N$
// is the largest number in the set.
#define MAX_INT_UNORDERED_TEST 8

typedef struct node {
  int data;
  struct node *next;
} Node, *Set;

void displaySet(Set);
void insertFirst(Set*, int);

Set unionSetOrderedTest(Set, Set);
Set unionSetUnorderedTest(Set A, Set B);

#endif
