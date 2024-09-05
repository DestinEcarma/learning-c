#include <stdio.h>

#include "helper.h"

int main() {
	Set sortedSetA;
	Set sortedSetB;

	initSet(&sortedSetA);
	initSet(&sortedSetB);

	insertSorted(&sortedSetA, 4);
	insertSorted(&sortedSetA, 1);
	insertSorted(&sortedSetA, 2);
	insertSorted(&sortedSetA, 3);

	insertSorted(&sortedSetB, 1);
	insertSorted(&sortedSetB, 2);
	insertSorted(&sortedSetB, 4);
	insertSorted(&sortedSetB, 3);

	printf("Set A: ");
	printSet(sortedSetA);

	printf("Set B: ");
	printSet(sortedSetB);

	printf("Is equal (sorted): %s\n", isEqualSetSortedTest(sortedSetA, sortedSetB) ? "true" : "false");

	makeNull(&sortedSetA);

	Set unsortedSetA;
	Set unsortedSetB;

	initSet(&unsortedSetA);
	initSet(&unsortedSetB);

	insertFirst(&unsortedSetA, 1);
	insertFirst(&unsortedSetA, 4);
	insertFirst(&unsortedSetA, 2);
	insertFirst(&unsortedSetA, 3);

	insertFirst(&unsortedSetB, 1);
	insertFirst(&unsortedSetB, 2);
	insertFirst(&unsortedSetB, 3);
	insertFirst(&unsortedSetB, 4);

	printf("Set A: ");
	printSet(unsortedSetA);

	printf("Set B: ");
	printSet(unsortedSetB);

	printf("Is equal (unsorted): %s\n", isEqualSetUnsortedTest(unsortedSetA, unsortedSetB) ? "true" : "false");

	makeNull(&unsortedSetA);

	return 0;
}
