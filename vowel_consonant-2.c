#include <stdio.h>

int main(void) {
	char letter;

	printf("Enter the letter: ");
	scanf(" %c", &letter);

	(
		(letter >= 'A' && letter <= 'Z') || (letter >= 'a' && letter <= 'z') ?
		(
			letter == 'A' || letter == 'a' ||
			letter == 'E' || letter == 'e' ||
			letter == 'I' || letter == 'i' ||
			letter == 'O' || letter == 'o' ||
			letter == 'U' || letter == 'u'
			? printf("Vowel") : printf("Consonant")
		)
		: printf("")
	);

	return 0;
}