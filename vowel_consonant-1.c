#include <stdio.h>

int main() {
	char letter;

	printf("Enter a single English alphabetic character: ");
	scanf("%c", &letter);

	if (letter >= 65 && letter <= 90 || letter >= 97 && letter <= 122) {
		switch (letter) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
			printf("The character is a vowel.");
			break;

		default:
			printf("The character is a consonant.");
			break;
		}
	} else printf("Invalid input.");

	return 0;
}