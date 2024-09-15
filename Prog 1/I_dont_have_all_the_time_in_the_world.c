#include <stdio.h>

int main(void) {
	int num;
	int max = 0, counter = 0;

	while (counter < 3 && num != 0) {
		printf("Enter a Number: ");
		scanf("%d", &num);

		if (num > max) {
			max = num;
			counter++;
		} else
			counter = 0;
	}

	if (counter >= 3)
		printf("\nProgram Ended due to 3 changes in the Greatest Number\n\n");
	else
		printf("\nProgram Ended due to an input of 0\n\n");

	printf("The Greatest Number is : %d", max);

	return 0;
}