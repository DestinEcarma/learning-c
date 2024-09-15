#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "helper.h"

void initialize(Students *list, int size) {
	list->elems = (Student *)malloc(sizeof(Student) * size);
	list->size = size;
	list->count = 0;
}

void insertAtPos(Student elem, Position pos, Students *list) {
	if (pos <= list->count) {
		if (list->count == list->size) {
			Student *newElems = (Student *)realloc(
				list->elems, sizeof(Student) * (list->size * 2));

			if (newElems != NULL) {
				list->elems = newElems;
				list->size *= 2;
			}
		}

		if (list->count < list->size) {
			memmove(list->elems + pos + 1, list->elems + pos,
					sizeof(Student) * (list->count - pos));

			list->elems[pos] = elem;
			list->count++;
		}
	}
}

void deleteAtPos(Position pos, Students *list) {
	if (pos < list->count) {
		memmove(list->elems + pos, list->elems + pos + 1,
				sizeof(Student) * (list->count - pos - 1));

		list->count--;

		if (list->size != 0 && list->count == (list->size / 2)) {
			Student *newElems = (Student *)realloc(
				list->elems, sizeof(Student) * (list->size / 2));

			if (newElems != NULL) {
				list->elems = newElems;
				list->size /= 2;
			}
		}
	}
}

Position locate(Student elem, Students *list) {
	Position pos = -1;

	for (int i = 0; i < list->count && pos == -1; i++) {
		if (list->elems[i].studentId == elem.studentId) {
			pos = i;
		}
	}

	return pos;
}

Student retrieve(Position pos, Students *list) {
	Student result = {.studentId = -1};

	if (pos < list->count) {
		result = list->elems[pos];
	}

	return result;
}

void makeNull(Students *list) { list->count = 0; }

void printList(Students *list) {
	for (int i = 0; i < list->count; i++) {
		Student *elem = list->elems + i;

		printf("ID: %d, Name: %s %c., %s, Course: %s, Year: %d\n",
			   elem->studentId, elem->name.first, elem->name.middle,
			   elem->name.last, elem->course, elem->year);
	}
};
