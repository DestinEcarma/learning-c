#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "helper.h"

int main() {
	Book *bookHead = NULL;
	Transaction *transactionHead = NULL;

	// Adding BookStatus
	addBook(&bookHead, 101, "C Programming");
	addBook(&bookHead, 102, "Data Structures");

	// Borrowing books
	borrowBook(bookHead, 101, "Alice", 35);
	logTransaction(&transactionHead, 1, 101, "Alice", BORROW);

	// Returning books
	returnBook(bookHead, 101);
	logTransaction(&transactionHead, 2, 101, "Alice", RETURN);

	// Display Reports
	displayOverdueBooks(bookHead);
	displayBorrowedBooks(bookHead);
	displayTransacitons(transactionHead);

	// Save data to files
	saveBooksToFile(bookHead, "books.txt");
	saveTransactionsToFile(transactionHead, "transaction.txt");

	return 0;
}
