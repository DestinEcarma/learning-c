#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char *a, const char *b) {
	if (a == NULL || *a == '\0') return 0;
	if (b == NULL || *b == '\0') return 1;

	while (*a == *b) {
		if (*(++a) == '\0') return 0;
		if (*(++b) == '\0') return 1;
	}

	return *a > *b;
}

int lexicographic_sort_reverse(const char *a, const char *b) {
	return !lexicographic_sort(a, b);
}

int strlen_distinct(const char *a) {
	int size = strlen(a);
	int result = 0;

	char *distinct_chars_s = calloc(1, size);

	for (int i = 0; i < size; i++) {
		int no_match = 1;
		for (int j = 0; j < result; j++) {
			if (distinct_chars_s[j] == a[i]) {
				no_match = 0;
				break;
			}
		}

		if (no_match) {
			distinct_chars_s[result] = a[i];
			result++;
		}
	}

	free(distinct_chars_s);

	return result;
}

int sort_by_number_of_distinct_characters(const char *a, const char *b) {
	int count_a = strlen_distinct(a);
	int count_b = strlen_distinct(b);

	if (count_a == count_b) return lexicographic_sort(a, b);
	return count_a > count_b;
}

int sort_by_length(const char *a, const char *b) {
	int length_a = strlen(a);
	int length_b = strlen(b);

	if (length_a == length_b) return lexicographic_sort(a, b);
	return length_a > length_b;
}

void string_sort(char **arr, const int len, int (*cmp_func)(const char *a, const char *b)) {
	int sorting = 1;

	for (int x = 0; x < len && sorting; x++) {
		sorting = 0;

		for (int y = 0; y < len - 1; y++) {
			if (strcmp(arr[y], arr[y + 1]) && (*cmp_func)(arr[y], arr[y + 1])) {
				char *temp = arr[y];

				arr[y] = arr[y + 1];
				arr[y + 1] = temp;
				sorting = 1;
			}
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);

	char **arr;
	arr = (char **)malloc(n * sizeof(char *));

	for (int i = 0; i < n; i++) {
		*(arr + i) = malloc(1024 * sizeof(char));
		scanf("%s", *(arr + i));
		*(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
	}

	printf("\n");

	string_sort(arr, n, lexicographic_sort);
	for (int i = 0; i < n; i++)
		printf("%s\n", arr[i]);
	printf("\n");

	string_sort(arr, n, lexicographic_sort_reverse);
	for (int i = 0; i < n; i++)
		printf("%s\n", arr[i]);
	printf("\n");

	string_sort(arr, n, sort_by_length);
	for (int i = 0; i < n; i++)
		printf("%s\n", arr[i]);
	printf("\n");

	string_sort(arr, n, sort_by_number_of_distinct_characters);
	for (int i = 0; i < n; i++)
		printf("%s\n", arr[i]);
	printf("\n");
}