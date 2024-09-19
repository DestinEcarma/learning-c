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

List newList(int capacity, size_t size);

size_t listLength(List *list);

void *listGet(List *list, size_t index);
bool listSet(List *list, size_t index, void *element);

bool listPush(List *list, void *element);
void *listPop(List *list);

#endif
