#include <stdio.h>

#include "helper.h"

int main() {
	// Populate the list and define the element
	Node a = { .data =  3, .next =  NULL };
	Node b = { .data =  7, .next =  &a };
	Node c = { .data =  1, .next =  &b };

	List L = &c;
	int elem = 2;

	printList(L);
	// Output: 1 7 3

	// Call the insertLast function
	insertLast(&L, elem);

	printList(L);
	// Output: 1 7 3 2
}
