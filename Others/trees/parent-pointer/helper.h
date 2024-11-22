#ifndef HELPER_H
#define HELPER_H

#define MAX 10

typedef struct {
	int data;
	int parent;
} ParentNode;

typedef ParentNode ParentList[MAX];

void initTree(ParentList list);

int insert(ParentList list, int data, int parent);
void display(ParentList list, int parent);

#endif
