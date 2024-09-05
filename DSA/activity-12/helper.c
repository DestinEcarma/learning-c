#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "helper.h"

void printSet(Set* set) {
	for (int i = 0; i < MAX; i++) {
		if ((*set)[i] > 0) {
			printf("%d ", i);
		}
	}

	printf("\n");
}

void zeroSet(Set* set) {
	memset(*set, 0, sizeof(short) * MAX);
}

void insertSet(Set* set, int data) {
	(*set)[data] = 1;
}

void removeSet(Set* set, int data) {
	(*set)[data] = 0;
}

Set* unionSet(Set* A, Set* B) {
	Set* result = (Set*)malloc(sizeof(Set));

	for (int i = 0; i < MAX; i++) {
		(*result)[i] = (*A)[i] || (*B)[i];
	}

	return result;
}

Set* intersectionSet(Set* A, Set* B) {
	Set* result = (Set*) malloc(sizeof(Set));

	for (int i = 0; i < MAX; i++) {
		(*result)[i] = (*A)[i] && (*B)[i];
	}

	return result;
}

Set* differenceSet(Set* A, Set* B) {
	Set* result = (Set*) malloc(sizeof(Set));

	for (int i = 0; i < MAX; i++) {
		(*result)[i] = (*A)[i] && !(*B)[i];
	}

	return result;
}

Set* complementSet(Set* A) {
	Set* result = (Set*) malloc(sizeof(Set));

	for (int i = 0; i < MAX; i++) {
		(*result)[i] = !(*A)[i];
	}

	return result;
}

bool isEqualSet(Set* A, Set* B) {
	int i = 0;
	int j = 0;

	while (
		i < MAX && j < MAX &&
		(*A)[i] == (*B)[j]
	) {
		i++;
		j++;
	}

	return i == MAX && j == MAX;
}
