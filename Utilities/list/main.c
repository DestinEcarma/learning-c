#include <stdio.h>

#include "list.h"

typedef struct {
	int x;
	int y;
	int z;
} Coordinate, Line[2];

int main() {
	int size = 10;

	List list = newList(size, sizeof(Line));

	printf("Push the elements\n");

	for (int i = 0; i < size; i++) {
		Line line = {{size - i, i, size + i}, {i, size + i, size - i}};

		listPush(&list, line);

		printf("Line %d: (%d, %d, %d) -> (%d, %d, %d)\n", i, line[0].x,
			   line[0].y, line[0].z, line[1].x, line[1].y, line[1].z);
	}

	printf("\nPop the elements\n");

	int length = listLength(&list);

	for (int i = 0; i < length; i++) {
		Line *line = (Line *)listGet(&list, i);

		printf("Line %d: (%d, %d, %d) -> (%d, %d, %d)\n", i, (*line)[0].x,
			   (*line)[0].y, (*line)[0].z, (*line)[1].x, (*line)[1].y,
			   (*line)[1].z);
	}

	return 0;
}
