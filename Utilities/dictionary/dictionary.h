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

// Create a new dictionary.
Dictionary newDictionary();

// Get a value from the dictionary.
void *dictionaryGet(Dictionary *dictionary, const char *key);

// Set a value in the dictionary.
bool dictionarySet(Dictionary *dictionary, const char *key, void *value,
				   size_t size);

// Unset a value in the dictionary.
bool dictionaryUnset(Dictionary *dictionary, const char *key);

#endif
