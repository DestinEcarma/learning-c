#include <stdio.h>

#include "helper.h"

void displayBitPattern(int value) {
	int byte = sizeof(value);
	int size = byte * 8;

	for (int i = size - 1; i >= 0 && (value >> i & 1) == 0; i--) {
		if (i % 8 == 0) {
			byte--;
		}
	}

	for (int i = byte * 8 - 1; i >= 0; i--) {
		printf("%d", value >> i & 1);

		if (i % 4 == 0) {
			printf(" ");
		}
	}

	printf("\n");
}
