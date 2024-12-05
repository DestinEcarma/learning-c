#include <stdio.h>

#include "defs.h"

#define z INF

int getMinWeightVertex(int visited[MAX], int weights[MAX]) {
	int minWeight = INF;
	int minVertex = -1;

	for (int i = 0; i < MAX; i++) {
		if (visited[i] == 0 && weights[i] < minWeight) {
			minWeight = weights[i];
			minVertex = i;
		}
	}

	return minVertex;
}

void dijkstra(Matrix matrix, Vertex source) {
	int visited[MAX] = {};
	int weights[MAX] = {};

	for (int i = 0; i < MAX; i++) {
		weights[i] = INF;
	}

	weights[source] = 0;

	for (int n = 1; n < MAX; n++) {
		Vertex minVertex = getMinWeightVertex(visited, weights);

		visited[minVertex] = 1;

		for (Vertex v = minVertex + 1; v < MAX; v++) {
			int weight = matrix[minVertex][v];

			if (weight + weights[minVertex] < weights[v]) {
				weights[v] = weight + weights[minVertex];
			}
		}
	}

	for (int i = 0; i < MAX; i++) {
		printf("%d ", weights[i]);
	}

	printf("\n");
}

int main() {
	Matrix matrix = {
		// clang-format off
		{0, 1, 1, z, z, 1},
		{1, 0, 3, 2, z, z},
		{1, 3, 0, 4, z, z},
		{z, 2, 4, 0, 3, z},
		{z, z, z, 3, 0, 7},
		{1, z, z, z, 7, 0},
		// clang-format on
	};

	dijkstra(matrix, 0);

	return 0;
}
