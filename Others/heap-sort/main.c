#include "helper.h"

int main() {
	int arr[] = {2, 5, 1, 6, 7, 9, 8, 3, 4, 0};
	int size = sizeof(arr) / sizeof(int);

	heapSort(arr, size);
	display(arr, size);

	return 0;
}
