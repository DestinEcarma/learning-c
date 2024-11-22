#ifndef HELPER_H
#define HELPER_H

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

#endif
