#include <stdio.h>

#include "helper.h"

int main() {
	Set A = NULL;
	Set B = NULL;

	insertFirst(&A, 5);
	insertFirst(&A, 3);
	insertFirst(&A, 1);
	insertFirst(&B, 6);
	insertFirst(&B, 4);
	insertFirst(&B, 2);

	printf("Set A: ");
	displaySet(A);
	printf("Set B: ");
	displaySet(B);

	Set C = unionSetOrderedTest(A, B);

	printf("Ordered Set C: ");
	displaySet(C);

	Set D = unionSetUnorderedTest(A, B);

	printf("Unordered Set D: ");
	displaySet(D);

	return 0;
}
