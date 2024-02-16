#include <stdio.h>

int isHappyNumber(int num) {
	int sum, digit;

	while (num != 1 && num != 4) {
		sum = 0;
		while (num > 0) {
			digit = num % 10;
			sum += digit * digit;
			num /= 10;
		}
		num = sum;
	}

	return num == 1;
}

int main() {
	int number;
	printf("Enter a number: ");
	scanf("%d", &number);

	if (isHappyNumber(number)) {
		printf("%d is a happy number.\n", number);
	} else {
		printf("%d is not a happy number.\n", number);
	}

	return 0;
}
