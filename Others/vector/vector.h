#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct {
	void *list;
	int length;
	int capacity;
} Vector;

Vector newVector(int capacity, size_t size);

int vectorLength(Vector *vector);

void *vectorGet(Vector *vector, int index, size_t size);
bool vectorSet(Vector *vector, int index, void *element, size_t size);

bool vectorPush(Vector *vector, void *element, size_t size);
void *vectorPop(Vector *vector, size_t size);

#endif
