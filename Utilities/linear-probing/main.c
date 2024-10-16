#include "dictionary.h"

int main() {
	Dictionary dict;
	dictionaryInit(&dict);

	dictionaryAdd(&dict, 1);
	dictionaryAdd(&dict, 21);
	dictionaryAdd(&dict, 11);
	dictionaryAdd(&dict, 2);
	dictionaryAdd(&dict, 3);
	dictionaryAdd(&dict, 4);
	dictionaryAdd(&dict, 9);
	dictionaryAdd(&dict, 8);
	dictionaryAdd(&dict, 0);
	dictionaryAdd(&dict, 7);
	dictionaryAdd(&dict, 8);
	dictionaryDisplay(&dict);

	dictionaryDelete(&dict, 1);
	dictionaryDelete(&dict, 21);
	dictionaryDisplay(&dict);

	dictionaryAdd(&dict, 11);
	dictionaryDisplay(&dict);

	return 0;
}
