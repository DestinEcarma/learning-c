#ifndef HELPER_H
#define HELPER_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct {
	void *list;
	size_t length;
	size_t capacity;
	size_t size;
} List;

// Create a new list.
List newList(int capacity, size_t size);

// Get the length of the list.
size_t listLength(List *list);

// Get an element from the list from the index.
void *listGet(List *list, size_t index);

// Set an element in the list from the index.
bool listSet(List *list, size_t index, void *element);

// Push an element to the list.
bool listPush(List *list, void *element);

// Pop an element from the list.
void *listPop(List *list);

#endif
