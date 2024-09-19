#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vector.h"

Vector newVector(int capacity, size_t size) {
	Vector vector;

	vector.list = (void *)malloc(capacity * size);
	vector.length = 0;
	vector.capacity = capacity;
	vector.size = size;

	return vector;
}

size_t vectorLength(Vector *vector) {
	return vector->length;
}

void *vectorGet(Vector *vector, size_t index) {
	if (index >= vector->length) {
		return NULL;
	}

	return vector->list + index * vector->size;
}

bool vectorSet(Vector *vector, size_t index, void *element) {
	if (index >= vector->length) {
		return false;
	}

	void *dest = vector->list + index * vector->size;
	memcpy(dest, element, vector->size);

	return true;
}

bool vectorPush(Vector *vector, void *element) {
	if (vector->length == vector->capacity) {
		void *newList =
			(void *)realloc(vector->list, vector->capacity * 2 * vector->size);

		if (newList == NULL) {
			return false;
		}

		vector->capacity *= 2;
		vector->list = newList;
	}

	void *dest = vector->list + vector->length * vector->size;
	memcpy(dest, element, vector->size);
	vector->length++;

	return true;
}

void *vectorPop(Vector *vector) {
	if (vector->length == 0) {
		return NULL;
	}

	vector->length--;
	return vector->list + vector->length * vector->size;
}
