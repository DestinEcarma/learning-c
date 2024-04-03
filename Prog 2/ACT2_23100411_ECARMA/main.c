#include <stdio.h>

// #include "ACT2_23100411_ECARMA_FUNCTIONS.h"

#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int testBool(bool (*func1)(int c), int (*func2)(int c)) {
	int result = 0;

	for (int i = 0; i < 128; i++) {
		if (func1(i) == (func2(i) ? 1 : 0)) continue;
		// printf("Error: %d %d %d\n", i, func1(i), func2(i) ? 1 : 0);
		result++;
	}

	return result;
}

int testChar(int (*func1)(int c), int (*func2)(int c)) {
	int result = 0;

	for (int i = 0; i < 128; i++) {
		if (func1(i) == func2(i)) continue;
		// printf("Error: %d %d %d\n", i, func1(i), func2(i));
		result++;
	}

	return result;
}

int testSize(size_t (*func1)(const char *str), size_t (*func2)(const char *str)) {
	int result = 0;

	for (int i = 0; i < 128; i++) {
		if (func1((char *)&i) == func2((char *)&i)) continue;
		// printf("Error: %d %d %d\n", i, func1((char *)&i), func2((char *)&i));
		result++;
	}

	return result;
}

int isEven(int a) {
	return a % 2 ? 0 : a;
}

int isOdd(int a) {
	return a % 2 ? a : 0;
}

int sum(int *(func)(int a)) {
	int sum = 0;

	for (int i = 1; i <= 10; i++) {
		sum += (int)func(i);
	}

	return sum;
}

int main(void) {
	// printf("Test my_isalnum(): %s\n", testBool(my_isalnum, isalnum) ? "Wrong" : "Correct");
	// printf("Test my_isalpha(): %s\n", testBool(my_isalpha, isalpha) ? "Wrong" : "Correct");
	// printf("Test my_isdigit(): %s\n", testBool(my_isdigit, isdigit) ? "Wrong" : "Correct");
	// printf("Test my_islower(): %s\n", testBool(my_islower, islower) ? "Wrong" : "Correct");
	// printf("Test my_isspace(): %s\n", testBool(my_isspace, isspace) ? "Wrong" : "Correct");
	// printf("Test my_isupper(): %s\n", testBool(my_isupper, isupper) ? "Wrong" : "Correct");
	// printf("Test my_tolower(): %s\n", testChar(my_tolower, tolower) ? "Wrong" : "Correct");
	// printf("Test my_toupper(): %s\n", testChar(my_toupper, toupper) ? "Wrong" : "Correct");
	// printf("Test my_strlen(): %s\n", testSize(my_strlen, strlen) ? "Wrong" : "Correct");

	// char str[] = "Hello";
	// char str2[] = "World";

	// printf("Test my_strcat(): %s\n", strcmp(my_strcat(str, str2), strcat(str, str2)) ? "Wrong" : "Correct");
	// printf("Test my_strcmp(): %s\n", my_strcmp(str, str2) != strcmp(str, str2) ? "Wrong" : "Correct");
	// printf("Test my_strcpy(): %s\n", strcmp(my_strcpy(str, str2), strcpy(str, str2)) ? "Wrong" : "Correct");

	int a = sum(isEven);

	printf("%d\n", a);	// 2 (2 + 0 + 0

	return 0;
}