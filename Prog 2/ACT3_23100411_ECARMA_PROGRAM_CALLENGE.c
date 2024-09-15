#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *SWEAR_WORDS[5] = {
	"fk", "sk", "ct", "st", "dk",
};

int filterWord(char *dest, const char *word) {
	if (strlen(word) != 4)
		return 0;

	for (int i = 0; i < 5; i++) {
		const char *swearWord = SWEAR_WORDS[i];

		char firstChar = word[0];
		char lastChar = word[3];

		if (tolower(firstChar) != swearWord[0])
			continue;
		if (tolower(lastChar) != swearWord[1])
			continue;

		dest[0] = firstChar;
		dest[1] = '*';
		dest[2] = '*';
		dest[3] = lastChar;
		dest[4] = '\0';
		return 1;
	}

	return 0;
}

char *filterPhrase(char *str) {
	int size = strlen(str);

	char *filtered = calloc(size, sizeof(char));

	char *filteredWord = malloc(5 * sizeof(char));
	char *token = strtok(str, " ");

	while (token != NULL) {
		int containsSwearWord = filterWord(filteredWord, token);

		strcat(filtered, containsSwearWord ? filteredWord : token);
		strcat(filtered, " ");

		token = strtok(NULL, " ");
	}

	free(filteredWord);
	free(token);
	return filtered;
}

int main(void) {
	char str[100];

	printf("Enter a phrase: ");
	fgets(str, 100, stdin);

	char *filteredStr = filterPhrase(str);

	printf("The filtered phrase is: %s\n", filteredStr);
	free(filteredStr);

	return 0;
}
