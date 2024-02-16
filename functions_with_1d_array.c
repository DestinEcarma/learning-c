#include <stdio.h>

#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))

int binaryConverter(int num) {
	int binary = 0;

	for (int placement = 1; num > 0; binary += placement * (num % 2), placement *= 10, num /= 2);

	return binary;
}

int main(void) {
	int x, y;

	printf("Enter X: ");
	scanf("%d", &x);

	printf("Enter Y: ");
	scanf("%d", &y);

	int min = MIN(x, y);
	int max = MAX(x, y);

	const int size = (max - min) + 1;
	int binaries[size];
	int *binary = binaries;

	for (int i = min; i <= max; i++, binary++) {
		*binary = binaryConverter(i);
	}

	for (int i = 0; i < size; i++) {
		printf("%d ", binaries[i]);
	}

	return 0;
}