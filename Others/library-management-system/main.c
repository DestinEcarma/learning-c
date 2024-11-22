#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { AVAILABLE, BORROWED, OVERDUE } BookStatus;

typedef enum { BORROW, RETURN } TransactionType;

typedef struct book {
	int bookId;
	char title[100];
	BookStatus status;
	char borrowerName[50];
	int daysBorrowed;
	struct book *next;
} Book;

typedef struct transaction {
	int transactionId;
	int bookId;
	char borrowerName[50];
	TransactionType type;
	struct transaction *next;
} Transaction;

// Book Management
void addBook(Book **head, int id, char *title);
void borrowBook(Book *head, int id, char *borrowerName, int days);
void returnBook(Book *head, int id);

// Overdue Management
void markOverdue(Book *head);

// Transactions
void logTransaction(Transaction **head, int TransactionId, int bookId,
					char *borrowerName, TransactionType type);

// Reports
void displayOverdueBooks(Book *head);
void displayBorrowedBooks(Book *head);
void displayTransacitons(Transaction *head);

// File Handling
void saveBooksToFile(Book *head, const char *filename);
void saveTransactionsToFile(Transaction *head, const char *filename);

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

// Book Management
void addBook(Book **head, int id, char *title) {
	Book *newBook = (Book *)malloc(sizeof(Book));

	if (newBook != NULL) {
		// Initialize the book
		newBook->bookId = id;
		strcpy(newBook->title, title);
		newBook->status = AVAILABLE;
		strcpy(newBook->borrowerName, "N/A");
		newBook->daysBorrowed = 0;

		newBook->next = *head;
		*head = newBook;
	}
}

void borrowBook(Book *head, int id, char *borrowerName, int days) {
	if (head != NULL) {
		while (!(head->bookId == id && head->status == AVAILABLE)) {
			head = head->next;
		}

		head->status = (days <= 30) ? BORROWED : OVERDUE;
		strcpy(head->borrowerName, borrowerName);
		head->daysBorrowed = days;
	}
}

void returnBook(Book *head, int id) {
	if (head != NULL) {
		while (!(head->bookId == id)) {
			head = head->next;
		}

		head->status = AVAILABLE;
		strcpy(head->borrowerName, "N/A");
		head->daysBorrowed = 0;
	}
}

// Overdue Management
void markOverdue(Book *head) {
	for (Book *curr = head; curr != NULL; curr = curr->next) {
		if (curr->status == BORROWED && curr->daysBorrowed > 30) {
			curr->status = OVERDUE;
		}
	}
}

// Transactions
void logTransaction(Transaction **head, int transactionId, int bookId,
					char *borrowerName, TransactionType type) {
	Transaction *newTransaction = (Transaction *)malloc(sizeof(Transaction));

	// Initialize the transaction
	newTransaction->transactionId = transactionId;
	newTransaction->bookId = bookId;
	strcpy(newTransaction->borrowerName, borrowerName);
	newTransaction->type = type;
	newTransaction->next = *head;

	*head = newTransaction;
}

// Reports
void displayOverdueBooks(Book *head) {
	for (Book *curr = head; curr != NULL; curr = curr->next) {
		if (curr->status == OVERDUE) {
			printf("ID: %d, Title: %s, Borrower: %s, Days Borrowed: %d\n",
				   curr->bookId, curr->title, curr->borrowerName,
				   curr->daysBorrowed);
		}
	}
}

void displayBorrowedBooks(Book *head) {
	for (Book *curr = head; curr != NULL; curr = curr->next) {
		if (curr->status == BORROWED) {
			printf("ID: %d, Title: %s, Borrower: %s, Days Borrowed: %d\n",
				   curr->bookId, curr->title, curr->borrowerName,
				   curr->daysBorrowed);
		}
	}
}

void displayTransacitons(Transaction *head) {
	for (Transaction *curr = head; curr != NULL; curr = curr->next) {
		printf("Transaction ID: %d, Book ID: %d, Borrower: %s, Type: %s\n",
			   curr->transactionId, curr->bookId, curr->borrowerName,
			   curr->type == BORROW ? "BORROW" : "RETURN");
	}
}

// File Handling
void saveBooksToFile(Book *head, const char *filename) {
	FILE *file = fopen(filename, "w");

	if (file != NULL) {
		for (Book *curr = head; curr != NULL; curr = curr->next) {
			fprintf(file,
					"ID: %d, Title: \"%s\", Status: %s, Borrower: %s, Days "
					"Borrowed: %d\n",
					curr->bookId, curr->title,
					curr->status == AVAILABLE  ? "AVAILABLE"
					: curr->status == BORROWED ? "BORROWED"
											   : "OVERDUE",
					curr->borrowerName, curr->daysBorrowed);
		}

		fclose(file);
	}
}

void saveTransactionsToFile(Transaction *head, const char *filename) {
	FILE *file = fopen(filename, "w");

	if (file != NULL) {
		for (Transaction *curr = head; curr != NULL; curr = curr->next) {
			fprintf(file,
					"Transaction ID: %d, Book ID: %d, Borrower: %s, Type: %s\n",
					curr->transactionId, curr->bookId, curr->borrowerName,
					curr->type == BORROW ? "BORROW" : "RETURN");
			curr = curr->next;
		}

		fclose(file);
	}
}
