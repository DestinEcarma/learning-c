#include <stdio.h>

#include "helper.h"

int main() {
	List list;
	List listUnique;
	List listSorted;

	initList(&list);
	initList(&listUnique);
	initList(&listSorted);

	printf("Insertion...\n\n");

	insertLast(&list, 1);
	insertLast(&list, 10);
	insertLast(&list, 5);

	insertLastUnique(&listUnique, 1);
	insertLastUnique(&listUnique, 7);
	insertLastUnique(&listUnique, 1);

	insertSorted(&listSorted, 5);
	insertSorted(&listSorted, 3);
	insertSorted(&listSorted, 5);

	printf("List: ");
	printList(&list);

	printf("List Unique: ");
	printList(&listUnique);

	printf("List Sorted: ");
	printList(&listSorted);

	printf("\nDeletion...\n\n");

	deleteElem(&listUnique, 10);
	deleteAllOccur(&listSorted, 5);

	printf("List Unique: ");
	printList(&listUnique);

	printf("List Sorted: ");
	printList(&listSorted);

	return 0;
}
