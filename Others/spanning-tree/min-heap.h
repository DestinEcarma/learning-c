#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include "defs.h"

#define MAX_SIZE 20

typedef struct {
	Edge list[MAX_SIZE];
	int lastIdx;
} MinHeap, List;

typedef struct {
	List edges;
	int cost;
} MST;

MinHeap createMinHeap(Matrix matrix);
void insertMinHeap(MinHeap *minHeap, Edge edge);
Edge deleteMinHeap(MinHeap *minHeap);

void printMinHeap(MinHeap *minHeap);

#endif
