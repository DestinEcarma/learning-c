#include <stdio.h>

#include "helper.h"

int getLargestChild(int arr[], int size, int parent) {
	int largest = parent;
	int left = parent * 2 + 1;
	int right = left + 1;

	if (left < size && arr[left] > arr[largest]) {
		largest = left;
	}

	if (right < size && arr[right] > arr[largest]) {
		largest = right;
	}

	return largest;
}

void maxHeapify(int arr[], int size, int parent) {
	int largest = getLargestChild(arr, size, parent);

	if (largest != parent) {
		int temp = arr[largest];
		arr[largest] = arr[parent];
		arr[parent] = temp;

		maxHeapify(arr, size, largest);
	}
}

void heapSort(int arr[], int size) {
	for (int i = (size - 1) / 2; i >= 0; i--) {
		maxHeapify(arr, size, i);
	}

	int lastIdx = size - 1;

	while (lastIdx >= 0) {
		int temp = arr[lastIdx];
		arr[lastIdx] = arr[0];
		arr[0] = temp;

		maxHeapify(arr, lastIdx--, 0);
	}
}

void display(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}

	printf("\n");
}
