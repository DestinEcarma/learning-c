#include <stdlib.h>

#include "defs.h"
#include "min-heap.h"

#define z INF

int *createComponents(int size) {
	int *components = malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++) {
		components[i] = i;
	}

	return components;
}

MST kruskals(Matrix matrix) {
	MST result = {.edges = {.lastIdx = -1}, .cost = 0};

	MinHeap minHeap = createMinHeap(matrix);

	int *components = createComponents(MAX);

	while (result.edges.lastIdx < MAX - 2) {
		Edge minEdge = deleteMinHeap(&minHeap);

		if (components[minEdge.u] != components[minEdge.v]) {
			int oldComponent = components[minEdge.u];

			for (int i = 0; i < MAX; i++) {
				if (components[i] == oldComponent) {
					components[i] = components[minEdge.v];
				}
			}

			result.cost += minEdge.weight;
			result.edges.list[++result.edges.lastIdx] = minEdge;
		}
	}

	free(components);
	return result;
}

int main() {
	Matrix matrix = {
		// clang-format off
		{0, 1, 1, z, z, 1},
		{1, 0, 3, 2, z, z},
		{1, 3, 0, 4, z, z},
		{z, 2, 4, 0, 3, z},
		{z, z, z, 3, 0, 1},
		{1, z, z, z, 1, 0},
		// clang-format on
	};

	MST mst = kruskals(matrix);

	printMinHeap(&mst.edges);

	return 0;
}
