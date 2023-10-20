#include <stdio.h>
#include <time.h>

unsigned int other(unsigned int num) {
	unsigned int firstDigit = num;
	unsigned int lastDigit = num % 10;
	unsigned int numberOfDigits = 0;

	// find the first digit and the number of digits
	while (firstDigit >= 10) {
		firstDigit /= 10;
		numberOfDigits++;
	}

	// calculate the powers of 10
	unsigned int powerOf10 = 1;
	for (unsigned int i = 0; i < numberOfDigits; i++) {
		powerOf10 *= 10;
	}

	// swap the first and last digits
	num = num - firstDigit * powerOf10 + lastDigit * powerOf10;
	num = num - lastDigit + firstDigit;

	return num;
}

unsigned int myMethod(unsigned int num) {
	int result = 0, placement = 1, _placement = 1;
	int first = 0, last = 0;
	int status = 1, counter = 0;

	while (num > 0) {
		int digit = num % 10;

		last = digit;
		num /= 10;
		
		if (status) {
			status = 0;
			first = digit;
		} else {
			if (num > 0) result += digit * placement;
			_placement *= 10;
		}
		
		placement *= 10;
		counter += 1;
	}
	
	result += first * _placement;
	if (counter > 1) result += last;

	return result;
}

int main(void) {
	float startTime = (float) clock()/ CLOCKS_PER_SEC;

	for (int i = 0; i < 100000000; i++) {
		other(i);
	}

	printf("%f\n", (float) clock() / CLOCKS_PER_SEC - startTime);

	startTime = (float) clock() / CLOCKS_PER_SEC;

	for (int i = 0; i < 100000000; i++) {
		myMethod(i);
	}

	printf("%f\n", (float) clock() / CLOCKS_PER_SEC - startTime);
	
	return 0;
}