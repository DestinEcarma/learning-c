#include <stdio.h>

#include "helper.h"

int main() {
	Students list;

	initialize(&list, 10);

	printf("Insertion...\n\n");

	insertAtPos((Student){.name = {"Destin", "Ecarma", 'R'},
						  .course = "BSCS",
						  .studentId = 2,
						  .year = 2},
				0, &list);

	insertAtPos((Student){.name = {"Destin", "Ripalda", 'E'},
						  .course = "BSCS",
						  .studentId = 1,
						  .year = 2},
				0, &list);

	insertAtPos((Student){.name = {"John", "Doe", 'J'},
						  .course = "BSCS",
						  .studentId = 3,
						  .year = 2},
				1, &list);

	printList(&list);

	printf("\nDeletion...\n\n");

	deleteAtPos(1, &list);

	printList(&list);

	return 0;
}
