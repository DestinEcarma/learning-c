#include <stdio.h>

int main() {
	int num = 76543;
	int v1, v2, v3, v4, v5;

	v1 = num / 10000;
	v2 = num % 10000 / 1000;
	v3 = num % 1000 / 100;
	v4 = num % 100 / 10;
	v5 = num % 10;

	printf("%d %d %d %d %d", v1, v2, v3, v4, v5);

	return 0;
}