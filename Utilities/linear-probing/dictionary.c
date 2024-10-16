#include <stdio.h>

#include "dictionary.h"

void dictionaryInit(Dictionary *dict) {
	for (int i = 0; i < MAX; i++) {
		dict->list[i] = EMPTY;
	}
}

int dictionaryHash(int data) {
	return data % MAX;
}

void dictionaryAdd(Dictionary *dict, int data) {
	int hash = dictionaryHash(data);

	int firstDeleted = -1;
	int attempt;

	for (attempt = 0; attempt < MAX; attempt++) {
		if (dict->list[hash] == EMPTY) {
			attempt = MAX;
		} else if (dict->list[hash] == DELETED && firstDeleted == -1) {
			firstDeleted = hash;
		} else {
			hash = (hash + 1) % MAX;
		}
	}

	if (attempt != MAX) {
		dict->list[hash] = data;
	} else if (firstDeleted != -1) {
		dict->list[firstDeleted] = data;
	}
}

void dictionaryDelete(Dictionary *dict, int data) {
	int hash = dictionaryHash(data);

	int attempt;

	for (attempt = 0; attempt < MAX; attempt++) {
		if (dict->list[hash] == data) {
			attempt = MAX;
		} else {
			hash = (hash + 1) % MAX;
		}
	}

	if (attempt != MAX) {
		dict->list[hash] = DELETED;
	}
}

void dictionaryDisplay(Dictionary *dict) {
	for (int i = 0; i < MAX; i++) {
		switch (dict->list[i]) {
			case EMPTY:
				printf("[%d]: EMPTY\n", i);
				break;
			case DELETED:
				printf("[%d]: DELETED\n", i);
				break;
			default:
				printf("[%d]: %d\n", i, dict->list[i]);
		}
	}

	printf("\n");
}
