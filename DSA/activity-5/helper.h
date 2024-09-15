#ifndef HELPER_H
#define HELPER_H

#define MAX 10

typedef struct {
	int elems[MAX];
	int count;
} StaticList;

typedef struct {
	int *elems;
	int count;
	int size;
} DynamicList;

void initializeVersion2(StaticList **);
void initializeVersion3(DynamicList *, int);
void initializeVersion4(DynamicList **, int);

#endif
