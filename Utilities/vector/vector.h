#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct {
	void *list;
	size_t length;
	size_t capacity;
	size_t size;
} Vector;

Vector newVector(int capacity, size_t size);

size_t vectorLength(Vector *vector);

void *vectorGet(Vector *vector, size_t index);
bool vectorSet(Vector *vector, size_t index, void *element);

bool vectorPush(Vector *vector, void *element);
void *vectorPop(Vector *vector);

#endif
