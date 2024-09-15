#include <stdio.h>
#include <string.h>

#include "helper.h"

void printList(List *list) {
	int lastIdx = list->count - 1;

	for (int i = 0; i < list->count; i++) {
		printf("%d", list->elems[i]);

		if (i != lastIdx) {
			printf(", ");
		}
	}

	printf("\n");
}

void initList(List *list) { list->count = 0; }

void insertLast(List *list, int elem) {
	if (list->count < MAX) {
		list->elems[list->count++] = elem;
	}
}

void insertLastUnique(List *list, int elem) {
	if (list->count < MAX) {
		int i = 0;

		while (i < list->count && list->elems[i] != elem) {
			i++;
		}

		if (i == list->count) {
			list->elems[list->count++] = elem;
		}
	}
}

void insertSorted(List *list, int elem) {
	if (list->count < MAX) {
		int i = 0;

		while (i < list->count && list->elems[i] < elem) {
			i++;
		}

		memmove(list->elems + i + 1, list->elems + i,
				sizeof(int) * (list->count - i));

		list->elems[i] = elem;
		list->count++;
	}
}

void deleteElem(List *list, int elem) {
	if (list->count > 0) {
		int i = 0;

		while (i < list->count && list->elems[i] != elem) {
			i++;
		}

		if (i < list->count) {
			memmove(list->elems + i, list->elems + i + 1,
					sizeof(int) * (list->count - i - 1));

			list->count--;
		}
	}
}

void deleteAllOccur(List *list, int elem) {
	int i = 0;

	while (i < list->count) {
		if (list->elems[i] == elem) {
			memmove(list->elems + i, list->elems + i + 1,
					sizeof(int) * (list->count - i - 1));

			list->count--;
		} else {
			i++;
		}
	}
}
