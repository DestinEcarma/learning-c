#include <stdio.h>

#include "helper.h"

int main() {
	ParentList list;

	initTree(list);

	int root = insert(list, 1, -1);
	int child1;

	child1 = insert(list, 2, root);
	child1 = insert(list, 3, child1);
	child1 = insert(list, 4, child1);
	child1 = insert(list, 5, child1);

	int child2;

	child2 = insert(list, 6, root);
	child2 = insert(list, 7, child2);
	child2 = insert(list, 8, child2);
	child2 = insert(list, 9, child2);
	child2 = insert(list, 10, child2);

	printf("Parent List of %d: ", child1);
	display(list, child1);

	printf("Parent List of %d: ", child2);
	display(list, child2);

	return 0;
}
