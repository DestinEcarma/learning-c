#include "defs.h"
#include "min-heap.h"

#define z INF

MST prim(Matrix matrix, Vertex source) {
	MST result = {.edges = {.lastIdx = -1}, .cost = 0};
	MinHeap minHeap = {.lastIdx = -1};

	int visited[MAX] = {};
	visited[source] = 1;

	for (Vertex u = 0; u < source; u++) {
		int weight = matrix[source][u];

		if (weight < INF) {
			insertMinHeap(&minHeap, (Edge){source, u, weight});
		}
	}

	while (result.edges.lastIdx < MAX - 2 && minHeap.lastIdx >= 0) {
		Edge minEdge = deleteMinHeap(&minHeap);

		if (visited[minEdge.u] != visited[minEdge.v]) {
			int from = (visited[minEdge.u] == 0) ? minEdge.u : minEdge.v;

			visited[from] = 1;

			result.cost += minEdge.weight;
			result.edges.list[++result.edges.lastIdx] = minEdge;

			for (Vertex to = 0; to < MAX; to++) {
				int weight = matrix[from][to];

				if (weight < INF && visited[to] == 0) {
					insertMinHeap(&minHeap, (Edge){from, to, weight});
				}
			}
		}
	}

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

	MST mst = prim(matrix, 1);

	printMinHeap(&mst.edges);

	return 0;
}
