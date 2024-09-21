#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "read-cli.h"

char *readCliString(const size_t length) {
	char prompt[length];

	fgets(prompt, length, stdin);

	prompt[strcspn(prompt, "\n")] = '\0';

	return strcpy(malloc(strlen(prompt) + 1), prompt);
}

char readCliChar() {
	char prompt;

	scanf("%c", &prompt);

	return prompt;
}

int readCliInt() {
	int prompt;

	scanf("%d", &prompt);

	return prompt;
}

float readCliFloat() {
	float prompt;

	scanf("%f", &prompt);

	return prompt;
}

double readCliDouble() {
	double prompt;

	scanf("%lf", &prompt);

	return prompt;
}
