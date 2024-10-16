#ifndef DICTIONARY_H
#define DICTIONARY_H

#define MAX 10

typedef struct {
	int list[MAX];
} Dictionary;

typedef enum {
	EMPTY = -1,
	DELETED = -2,
} DictionaryState;

void dictionaryInit(Dictionary *dict);

int dictionaryHash(int data);

void dictionaryAdd(Dictionary *dict, int data);
void dictionaryDelete(Dictionary *dict, int data);

void dictionaryDisplay(Dictionary *dict);

#endif
