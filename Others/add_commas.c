#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *addCommas(int number) {
	char buffer[20];
	sprintf(buffer, "%d", number);

	int length = strlen(buffer);
	int commaCount = (length - 1) / 3;
	int newLength = length + commaCount;

	char *result = malloc(newLength + 1);
	int j = newLength - 1;

	for (int i = length - 1; i >= 0; i--) {
		result[j--] = buffer[i];

		if ((length - i) % 3 == 0 && i > 0) {
			result[j--] = ',';
		}
	}

	result[newLength] = '\0';
	return result;
}

int main(void) {
	char *salary;

	salary = "1,234,567";

	printf("%s", salary);

	return 0;
}