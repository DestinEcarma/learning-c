#include <stdio.h>

int main() {
	int num;

	printf("Enter a number: ");
	scanf("%d", &num);

	long long int factorial = 1;
	int i = 1;

	while (i <= num) {
		factorial *= i;
		i++;
	}

	printf("Factorial of %d is %lld", num, factorial);

	return 0;
}
