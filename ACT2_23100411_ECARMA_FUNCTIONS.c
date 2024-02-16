#include "ACT2_23100411_ECARMA_FUNCTIONS.h"

#include <stdio.h>
#include <stdlib.h>

// ctype Library
bool my_isalnum(int c) {
	return my_isalpha(c) || my_isdigit(c);
}

bool my_isalpha(int c) {
	return (c >= 'A' && c <= 'Z') ||
		   (c >= 'a' && c <= 'z');
}

bool my_isdigit(int c) {
	return c >= '0' && c <= '9';
}

bool my_islower(int c) {
	return c >= 'a' && c <= 'z';
}

bool my_isspace(int c) {
	return c == ' ' || (c >= '\t' && c <= '\r');
}

bool my_isupper(int c) {
	return c >= 'A' && c <= 'Z';
}

int my_tolower(int c) {
	if (!my_isalpha(c)) return c;
	if (my_islower(c)) return c;
	return c + 32;
}

int my_toupper(int c) {
	if (!my_isalpha(c)) return c;
	if (my_isupper(c)) return c;
	return c - 32;
}

// string Library
size_t my_strlen(const char *str) {
	int size = 0;

	while (*str != '\0') {
		size++;
		str++;
	}

	return size;
}

char *my_strcat(char *dest, const char *src) {
	char *ptr = dest + my_strlen(dest);

	while (*src != '\0') {
		*ptr++ = *src++;
	}

	*ptr = '\0';

	return dest;
}

char *my_strcpy(char *dest, const char *src) {
	char *ptr;

	for (ptr = dest; *src != '\0'; src++, dest++) {
		*dest = *src;
	}

	*dest = '\0';

	return ptr;
}

int my_strcmp(const char *str1, const char *str2) {
	while (*str1 && (*str1 == *str2)) {
		str1++;
		str2++;
	}
	return (*str1 < *str2) ? -1 : (*str1 > *str2) ? 1
												  : 0;
}

// Counter
int my_counterDigits(const char *str) {
	int digit = 0;

	while (*str != '\0') {
		if (my_isdigit(*str)) digit++;
		str++;
	}

	return digit;
}