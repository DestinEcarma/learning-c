#include "read-cli.h"
#include <stdio.h>

int main() {
	printf("Enter a string: ");
	char *string = readCliString(10);

	printf("Enter a character: ");
	char character = readCliChar();

	printf("Enter an integer: ");
	int integer = readCliInt();

	printf("Enter a float: ");
	float floating = readCliFloat();

	printf("Enter a double: ");
	double doublet = readCliDouble();

	printf("\nString: %s", string);
	printf("Character: %c\n", character);
	printf("Integer: %d\n", integer);
	printf("Float: %f\n", floating);
	printf("Double: %lf\n", doublet);

	return 0;
}
