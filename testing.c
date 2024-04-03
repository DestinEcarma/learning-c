#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int originalArray[5] = {1, 2, 3, 4, 5};
	int newArray[6];  // New array with extra space for the new element

	int position = 2;	// Position to insert the new element
	int newValue = 10;	// Value of the new element

	// Copy the elements before the insertion point from the original array to the new array
	memmove(newArray, originalArray, position * sizeof(int));

	// Insert the new element into the new array
	newArray[position] = newValue;

	// Copy the elements after the insertion point from the original array to the new array
	memmove(newArray + position + 1, originalArray + position, (5 - position) * sizeof(int));

	// Output the new array
	printf("New array after insertion: ");
	for (int i = 0; i < 6; i++) {
		printf("%d ", newArray[i]);
	}
	printf("\n");

	return 0;
}