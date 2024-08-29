#include "helper.h"

int main() {
	Cursor cursor;
	List head = -1;
	initList(&cursor);

	deleteData(&cursor, &head, 69);

	insertLast(&cursor, &head, 10);
	insertLast(&cursor, &head, 20);
	insertLast(&cursor, &head, 30);
	insertLast(&cursor, &head, 40);
	insertLast(&cursor, &head, 50);

	deleteData(&cursor, &head, 69);

	printList(&cursor, head);

	while (head != -1) {
		int data = cursor.nodes[head].data;
		deleteData(&cursor, &head, data);
		printList(&cursor, head);
	}

	return 0;
}
