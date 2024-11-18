#include <stdio.h>

#include "helper.h"

void initTree(ParentList list) {
	for (int i = 0; i < MAX; i++) {
		list[i].data = -1;
		list[i].parent = -1;
	}
}

int insert(ParentList list, int data, int parent) {
	int temp = -1;

	for (int i = 0; i < MAX && temp == -1; i++) {
		if (list[i].data == -1) {
			list[i].data = data;
			list[i].parent = parent;
			temp = i;
		}
	}

	return temp;
}

void display(ParentList list, int parent) {
	if (parent != -1) {
		printf("%d ", list[parent].data);
		display(list, list[parent].parent);
	} else {
		printf("\n");
	}
}
