#include <stdio.h>

int main(void) {
	int num;

	scanf("%d", &num);

	int currentDiv = 2;
	int maxPrime = 0;

	while (num > 0) {
		if (num % currentDiv != 0)
			currentDiv++;
		else {
			maxPrime = num;
			num /= currentDiv;
			if (num == 1)
				break;
		}
	}

	printf("%d", maxPrime);

	return 0;
}