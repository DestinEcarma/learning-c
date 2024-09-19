#include <stdio.h>

#include "vector.h"

typedef struct {
	int x;
	int y;
} Point;

int main() {
	Vector vector = newVector(5, sizeof(Point[2]));

	for (int i = 0; i < 10; i++) {
		Point point = {i, 9 - i};
		Point point2 = {9 - i, i};

		Point points[2] = {point, point2};

		vectorPush(&vector, points, sizeof(Point[2]));

		printf("Pushed (%d, %d) (%d, %d)\n", point.x, point.y, point2.x,
			   point2.y);
	}

	printf("Popping\n");

	while (vectorLength(&vector) > 0) {
		Point(*element)[2] = (Point(*)[2])vectorPop(&vector, sizeof(Point[2]));

		printf("(%d, %d) (%d, %d)\n", (*element)[0].x, (*element)[0].y,
			   (*element)[1].x, (*element)[1].y);
	}

	return 0;
}
