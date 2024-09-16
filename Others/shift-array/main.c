#include <stdio.h>

#include "helper.h"

int main() {
	int arr[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	printf("Original array:\n");
	printArray(arr);

	leftShift(arr);
	printf("After left shift:\n");
	printArray(arr);

	rightShift(arr);
	printf("After right shift:\n");
	printArray(arr);

	return 0;
}
