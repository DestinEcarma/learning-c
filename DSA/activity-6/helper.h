#ifndef HELPER_H
#define HELPER_H

typedef char String[50];
typedef int Position;

typedef struct {
	String first;
	String last;
	char middle;
} Name;

typedef struct {
	int studentId;
	int year;
	String course;
	Name name;
} Student;

typedef struct {
	Student *elems;
	int count;
	int size;
} Students;

void initialize(Students *, int);

void insertAtPos(Student, Position, Students *);
void deleteAtPos(Position, Students *);

Position locate(Student, Students *);
Student retrieve(Position, Students *);

void makeNull(Students *);
void printList(Students *);

#endif
