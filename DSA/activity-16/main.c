#include "helper.h"

int main() {
	Matrix matrix = {{INFINITY, 1, 3, 6, 9},
					 {1, INFINITY, 2, 5, 7},
					 {3, 2, INFINITY, 4, 6},
					 {6, 5, 4, INFINITY, 8},
					 {9, 7, 6, 8, INFINITY}};

	EdgeNode *edges = createEdgeNode(matrix);

	displayEdgeNode(edges);

	return 0;
}
