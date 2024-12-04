#include <stdio.h>

#include "min-heap.h"

int getMinChild(MinHeap *minHeap, int parent) {
	int leftChild = parent * 2 + 1;
	int rightChild = leftChild + 1;

	return minHeap->list[leftChild].weight < minHeap->list[rightChild].weight
			   ? leftChild
			   : rightChild;
}

MinHeap createMinHeap(Matrix matrix) {
	MinHeap result = {.lastIdx = -1};

	for (Vertex v = 1; v < MAX; v++) {
		for (Vertex u = 0; u < v; u++) {
			int weight = matrix[v][u];

			if (weight < INF) {
				insertMinHeap(&result, (Edge){v, u, weight});
			}
		}
	}

	return result;
}

void insertMinHeap(MinHeap *minHeap, Edge edge) {
	if (minHeap->lastIdx + 1 < MAX_SIZE) {
		int child = ++minHeap->lastIdx;
		int parent = (child - 1) / 2;

		while (child > 0 && minHeap->list[parent].weight > edge.weight) {
			minHeap->list[child] = minHeap->list[parent];

			child = parent;
			parent = (child - 1) / 2;
		}

		minHeap->list[child] = edge;
	}
}

Edge deleteMinHeap(MinHeap *minHeap) {
	Edge temp = {-1, -1, -1};

	if (minHeap->lastIdx >= 0) {
		temp = minHeap->list[0];

		Edge data = minHeap->list[minHeap->lastIdx--];

		int parent = 0;
		int child = getMinChild(minHeap, parent);

		while (child <= minHeap->lastIdx &&
			   minHeap->list[child].weight < data.weight) {
			minHeap->list[parent] = minHeap->list[child];

			parent = child;
			child = getMinChild(minHeap, parent);
		}

		minHeap->list[parent] = data;
	}

	return temp;
}

void printMinHeap(MinHeap *minHeap) {
	int size = minHeap->lastIdx;

	for (int i = 0; i <= size; i++) {
		Edge temp = minHeap->list[i];
		printf("(%d, %d, %d) ", temp.u, temp.v, temp.weight);
	}

	printf("\n");
}
