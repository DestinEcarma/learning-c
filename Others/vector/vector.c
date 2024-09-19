#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vector.h"

Vector newVector(int capacity, size_t size) {
	Vector vector;

	vector.list = (void *)malloc(capacity * size);
	vector.length = 0;
	vector.capacity = capacity;

	return vector;
}

int vectorLength(Vector *vector) {
	return vector->length;
}

void *vectorGet(Vector *vector, int index, size_t size) {
	if (index < 0 || index >= vector->length) {
		return NULL;
	}

	return vector->list + index * size;
}

bool vectorSet(Vector *vector, int index, void *element, size_t size) {
	if (index < 0 || index >= vector->length) {
		return false;
	}

	void *dest = vector->list + index * size;
	memcpy(dest, element, size);

	return true;
}

bool vectorPush(Vector *vector, void *element, size_t size) {
	if (vector->length == vector->capacity) {
		void *newList =
			(void *)realloc(vector->list, vector->capacity * 2 * size);

		if (newList == NULL) {
			return false;
		}

		vector->capacity *= 2;
		vector->list = newList;
	}

	void *dest = vector->list + vector->length * size;
	memcpy(dest, element, size);
	vector->length++;

	return true;
}

void *vectorPop(Vector *vector, size_t size) {
	if (vector->length == 0) {
		return NULL;
	}

	vector->length--;
	return vector->list + vector->length * size;
}
