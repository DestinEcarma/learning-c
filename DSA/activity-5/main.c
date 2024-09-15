#include <stdio.h>

#include "helper.h"

int main() {
	StaticList *version2;
	DynamicList version3;
	DynamicList *version4;

	printf("Initialization...\n\n");

	initializeVersion2(&version2);
	initializeVersion3(&version3, 10);
	initializeVersion4(&version4, 10);

	return 0;
}
