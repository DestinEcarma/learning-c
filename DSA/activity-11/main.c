#include <stdio.h>

#include "helper.h"

int main() {
	Cursor cursorSorted, cursorUnordered;

	initList(&cursorSorted);
	initList(&cursorUnordered);

	List ASorted = -1;
	List BSorted = -1;

	List AUnordered = -1;
	List BUnordered = -1;

	insertSorted(&cursorSorted, &ASorted, 1);
	insertSorted(&cursorSorted, &ASorted, 2);
	insertSorted(&cursorSorted, &ASorted, 3);
	insertSorted(&cursorSorted, &ASorted, 4);
	insertSorted(&cursorSorted, &ASorted, 5);

	insertSorted(&cursorSorted, &BSorted, 1);
	insertSorted(&cursorSorted, &BSorted, 2);
	insertSorted(&cursorSorted, &BSorted, 3);
	insertSorted(&cursorSorted, &BSorted, 4);
	insertSorted(&cursorSorted, &BSorted, 5);

	insertFirst(&cursorUnordered, &AUnordered, 1);
	insertFirst(&cursorUnordered, &AUnordered, 2);
	insertFirst(&cursorUnordered, &AUnordered, 3);
	insertFirst(&cursorUnordered, &AUnordered, 4);

	insertFirst(&cursorUnordered, &BUnordered, 1);
	insertFirst(&cursorUnordered, &BUnordered, 2);
	insertFirst(&cursorUnordered, &BUnordered, 3);
	insertFirst(&cursorUnordered, &BUnordered, 2);

	printf("A sorted: ");
	printList(&cursorSorted, ASorted);

	printf("B sorted: ");
	printList(&cursorSorted, BSorted);

	printf("A == B: %s\n\n", isEqualListOrderedTest(&cursorSorted, ASorted, BSorted) ? "TRUE" : "FALSE");

	printf("A unordered: ");
	printList(&cursorUnordered, AUnordered);

	printf("B unordered: ");
	printList(&cursorUnordered, BUnordered);

	printf("A == B: %s\n", isEqualListUnorderedTest(cursorUnordered, AUnordered, BUnordered) ? "TRUE" : "FALSE");

	return 0;
}
