#include <stdio.h>

#include "helper.h"

int main() {
	int value;

	printf("Enter a value: ");
	scanf("%d", &value);

	displayBitPattern(value);

	return 0;
}
