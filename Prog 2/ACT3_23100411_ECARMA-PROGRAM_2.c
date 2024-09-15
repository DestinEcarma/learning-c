#include <stdio.h>
#include <stdlib.h>

char *strclone(const char *src, int size) {
	char *dest = malloc((size + 1) * sizeof(char));

	for (int i = 0; i < size; i++) {
		dest[i] = src[i];
	}

	dest[size] = '\0';
	return dest;
}

char *strcopy(char *dest, const char *src) {
	for (int i = 0; src[i] != '\0'; i++) {
		dest[i] = src[i];
	}

	return dest;
}

char *getLongestWord(char *str) {
	int maxLength = 0;
	int currentLength = 0;

	char *longestWord = calloc(100, sizeof(char));
	char *currentWord = calloc(100, sizeof(char));

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == ' ') {
			if (currentLength > maxLength) {
				strcopy(longestWord, currentWord);
				maxLength = currentLength;
			}

			currentLength = 0;
		} else {
			currentWord[currentLength++] = str[i];
		}
	}

	char *result = strclone(longestWord, maxLength);
	free(longestWord);
	free(currentWord);

	return result;
}

int main(void) {
	char str[100];

	printf("Enter a phrase: ");
	fgets(str, 100, stdin);

	char *word = getLongestWord(str);

	printf("The longest word is: %s\n", word);

	return 0;
}
