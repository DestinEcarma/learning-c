#include <stdio.h>

#include "helper.h"

int main() {
	List list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	int result = binary_search(list, MAX, 5);

	printf("Result: %d\n", result);

	return 0;
}
