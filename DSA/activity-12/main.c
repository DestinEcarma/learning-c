#include <stdio.h>
#include <stdlib.h>

#include "helper.h"

int main() {
	Set A = {};
	Set B = {};

	insertSet(&A, 1);
	insertSet(&A, 3);
	insertSet(&A, 5);
	insertSet(&A, 7);

	insertSet(&B, 2);
	insertSet(&B, 4);
	insertSet(&B, 6);
	insertSet(&B, 8);
	insertSet(&B, 7);

	printf("Set A: ");
	printSet(&A);
	printf("Set B: ");
	printSet(&B);

	Set* AuB = unionSet(&A, &B);

	printf("Union: ");
	printSet(AuB);

	Set* AnB = intersectionSet(&A, &B);

	printf("Intersection: ");
	printSet(AnB);

	Set* AdB = differenceSet(&A, &B);

	printf("Difference: ");
	printSet(AdB);

	Set* Ac = complementSet(&A);

	printf("Complement of A: ");
	printSet(Ac);

	Set* Bc = complementSet(&B);

	printf("Complement of B: ");
	printSet(Bc);

	free(AuB);
	free(AnB);
	free(AdB);
	free(Ac);
	free(Bc);

	Set SortedA = {};
	Set SortedB = {};

	insertSet(&SortedA, 1);
	insertSet(&SortedA, 3);
	insertSet(&SortedA, 5);
	insertSet(&SortedA, 7);

	insertSet(&SortedB, 1);
	insertSet(&SortedB, 3);
	insertSet(&SortedB, 5);
	insertSet(&SortedB, 7);

	printf("Sorted A: ");
	printSet(&SortedA);

	printf("Sorted B: ");
	printSet(&SortedB);

	printf("Is equal (sorted): %s\n", isEqualSet(&SortedA, &SortedB) ? "true" : "false");

	return 0;
}
