#include <stdio.h>

#include "vector.h"

typedef struct {
	int x;
	int y;
} Point, Line[2];

int main() {
	int size = 5;

	Vector vector = newVector(size, sizeof(Line));

	int n = 10;

	printf("Push the elements\n");

	for (int i = 0; i < n; i++) {
		Line line = {{i, n - i}, {-n + i, -i}};

		vectorPush(&vector, line);

		printf("Line: (%d, %d) (%d, %d)\n", line[0].x, line[0].y, line[1].x,
			   line[1].y);
	}

	printf("\nPop the elements\n");

	while (vectorLength(&vector) > 0) {
		Line *line = (Line *)vectorPop(&vector);

		printf("Line: (%d, %d) (%d, %d)\n", (*line)[0].x, (*line)[0].y,
			   (*line)[1].x, (*line)[1].y);
	}

	return 0;
}