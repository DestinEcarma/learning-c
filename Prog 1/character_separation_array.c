#include <stdio.h>

#define LEN 8

int main(void) {
	char arr[LEN] = { 0 };

	printf("Enter %d character:\n", LEN);

	for (int i = 0; i < LEN; i++) {
		scanf("%c", arr + i);
		if (arr[i] == '\n') i--;
	}

	printf("Array elements:\n");

	for (int i = 0; i < LEN; i++) {
		printf("%c", arr[i]);
		if (i < LEN - 1) printf("-");
	}

	return 0;
}