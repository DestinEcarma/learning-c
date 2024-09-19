#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

Dictionary newDictionary() {
	Dictionary dictionary;

	dictionary.list =
		(KeyValuePair *)malloc(INITIAL_CAPACITY * sizeof(KeyValuePair));
	dictionary.length = 0;
	dictionary.capacity = INITIAL_CAPACITY;

	return dictionary;
}

void *dictionaryGet(Dictionary *dictionary, char *key) {
	for (size_t i = 0; i < dictionary->length; i++) {
		if (strcmp(dictionary->list[i].key, key) == 0) {
			return dictionary->list[i].value;
		}
	}

	return NULL;
}

bool dictionarySet(Dictionary *dictionary, char *key, void *value,
				   size_t size) {
	KeyValuePair *list = dictionary->list;
	size_t length = dictionary->length;

	for (size_t i = 0; i < length; i++) {
		if (strcmp(list[i].key, key) == 0) {
			if (list[i].size > size) {
				void *newValue = (void *)realloc(list[i].value, size);

				if (newValue == NULL) {
					return false;
				}

				list[i].value = newValue;
				list[i].size = size;
			}

			memcpy(list[i].value, value, size);
			return true;
		}
	}

	if (length == dictionary->capacity) {
		KeyValuePair *newList = (KeyValuePair *)realloc(
			list, dictionary->capacity * 2 * sizeof(KeyValuePair));

		if (newList == NULL) {
			return false;
		}

		dictionary->capacity *= 2;
		dictionary->list = newList;
		list = newList;
	}

	list[length].key = (char *)malloc(strlen(key) + 1);
	list[length].value = (void *)malloc(size);
	list[length].size = size;

	if (list[length].key == NULL || list[length].value == NULL) {
		free(list[length].key);
		return false;
	}

	strcpy(list[length].key, key);
	memcpy(list[length].value, value, size);

	dictionary->length++;

	return true;
}

bool dictionaryRemove(Dictionary *dictionary, char *key) {
	KeyValuePair *list = dictionary->list;
	size_t length = dictionary->length;

	for (size_t i = 0; i < length; i++) {
		if (strcmp(list[i].key, key) == 0) {
			free(list[i].key);
			free(list[i].value);

			for (size_t j = i; j < length - 1; j++) {
				list[j] = list[j + 1];
			}

			dictionary->length--;

			return true;
		}
	}

	return false;
}
