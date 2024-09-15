#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char str[100];

	printf("Enter a string: ");
	fgets(str, 100, stdin);

	int *uniqueChars = calloc(128, sizeof(int));

	for (int i = 0; str[i]; i++) {
		uniqueChars[(int)str[i]]++;
	}

	for (int i = 0; i < 128; i++) {
		if (!uniqueChars[i])
			continue;
		printf("%c: %d\n", i, uniqueChars[i]);
	}

	free(uniqueChars);
	return 0;
}
