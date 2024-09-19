#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 10

typedef struct {
	char *key;
	void *value;
	size_t size;
} KeyValuePair;

typedef struct {
	KeyValuePair *list;
	size_t length;
	size_t capacity;
} Dictionary;

Dictionary newDictionary();

void *dictionaryGet(Dictionary *dictionary, const char *key);

bool dictionarySet(Dictionary *dictionary, const char *key, void *value,
				   size_t size);

bool dictionaryRemove(Dictionary *dictionary, const char *key);

#endif
