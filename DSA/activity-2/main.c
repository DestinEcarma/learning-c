#include <stdio.h>

#include "helper.h"

int main() {
	List listNoHeader;
	List listWithHeader;

	initListNoHeader(&listNoHeader);
	initListWithHeader(&listWithHeader);

	printf("Insertion...\n\n");

	insertLastPPN(&listNoHeader, 1);
	insertLastPPN(&listNoHeader, 3);
	insertLastPPN(&listNoHeader, 5);

	insertLastLookAhead(listWithHeader, 2);
	insertLastLookAhead(listWithHeader, 4);
	insertLastLookAhead(listWithHeader, 6);

	printf("List No Header: ");
	printList(listNoHeader);

	printf("List With Header: ");
	printList(listWithHeader);

	printf("\nDeletion...\n\n");

	deleteElemPPN(&listNoHeader, 3);
	deleteElemLookAhead(listWithHeader, 2);

	printf("List No Header: ");
	printList(listNoHeader);

	printf("List With Header: ");
	printList(listWithHeader);

	return 0;
}
