#include <stdio.h>

#include "helper.h"

void printArray(int arr[MAX]) {
	for (int i = 0; i < MAX; i++) {
		printf("%d", arr[i]);

		if (i < MAX - 1) {
			printf(", ");
		}
	}

	printf("\n");
}

void leftShift(int arr[MAX]) {
	for (int i = 0; i < MAX - 1; i++) {
		arr[i] = arr[i + 1];
	}
}

void rightShift(int arr[MAX]) {
	for (int i = MAX - 1; i > 0; i--) {
		arr[i] = arr[i - 1];
	}
}
