#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

List newList(int capacity, size_t size) {
	List list;

	list.list = (void *)malloc(capacity * size);
	list.length = 0;
	list.capacity = capacity;
	list.size = size;

	return list;
}

size_t listLength(List *list) {
	return list->length;
}

void *listGet(List *list, size_t index) {
	if (index >= list->length) {
		return NULL;
	}

	return list->list + index * list->size;
}

bool listSet(List *list, size_t index, void *element) {
	if (index >= list->length) {
		return false;
	}

	void *dest = list->list + index * list->size;
	memcpy(dest, element, list->size);

	return true;
}

bool listPush(List *list, void *element) {
	if (list->length == list->capacity) {
		return false;
	}

	void *dest = list->list + list->length * list->size;
	memcpy(dest, element, list->size);
	list->length++;

	return true;
}

void *listPop(List *list) {
	if (list->length == 0) {
		return NULL;
	}

	list->length--;
	return list->list + list->length * list->size;
}
