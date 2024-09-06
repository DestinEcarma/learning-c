#include <stdio.h>

#include "helper.h"

void displayBitPattern(void* value, int size) {
	unsigned char* bytes = (unsigned char*) value;

	for (int i = size - 1; i >= 0 && size > 1; i--) {
		int j = 7;

		while (j >= 0) {
			if ((bytes[i] >> j & 1) == 1) {
				i = -1;
			}

			j--;
		}

		if (j < 0 && i >= 0) {
			size--;
		}
	}

	for (int i = size - 1; i >= 0; i--) {
		for (int j = 7; j >= 0; j--) {
			printf("%d", bytes[i] >> j & 1);

			if (j == 4) {
				printf(" ");
			}
		}

		printf(" ");
	}

	printf("\n");
}
