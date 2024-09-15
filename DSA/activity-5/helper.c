#include <stdlib.h>

#include "helper.h"

void initializeVersion2(StaticList **list) {
	*list = (StaticList *)malloc(sizeof(StaticList));

	if (*list != NULL) {
		(*list)->count = 0;
	}
}

void initializeVersion3(DynamicList *list, int size) {
	list->elems = (int *)malloc(sizeof(int) * size);
	list->size = size;
	list->count = 0;
}

void initializeVersion4(DynamicList **list, int size) {
	*list = (DynamicList *)malloc(sizeof(DynamicList));

	if (*list != NULL) {
		(*list)->elems = (int *)malloc(sizeof(int) * size);
		(*list)->size = size;
		(*list)->count = 0;
	}
}
