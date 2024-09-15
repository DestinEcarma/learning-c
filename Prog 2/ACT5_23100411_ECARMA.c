#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define STR_LEN 30

typedef char String[STR_LEN];

typedef struct {
	String fname;
	String lname;
} Name, *NameList;

typedef struct {
	Name name;
	char sex;
	int id;
} Student, *StudentList;

void displayName(Name *n) { printf("%s, %s\n", n->lname, n->fname); }

void displayStudent(Student *s) {
	displayName(&s->name);
	printf("Student Id: %d\n", s->id);
	printf("Sex: %c\n", s->sex);
}

Student getStudent() {
	Student s;

	printf("First name: ");
	scanf("%s", s.name.fname);

	printf("Last name: ");
	scanf("%s", s.name.lname);

	printf("ID: ");
	scanf("%d", &s.id);

	printf("Sex (M/f): ");
	scanf("\n%c", &s.sex);

	return s;
}

void addStudent(StudentList list, int *count, Student s) {
	list[(*count)++] = s;
}

int isFemale(Student *s) { return toupper(s->sex) == 'F'; }

int countFemale(StudentList list, int size) {
	int count = 0;

	for (int i = 0; i < size; i++) {
		if (isFemale(&list[i]))
			count++;
	}

	return count;
}

void getFemaleNames(StudentList list, int size, NameList names,
					int *femaleCount) {
	for (int i = 0; i < size; i++) {
		Student *s = &list[i];
		if (!isFemale(s))
			continue;

		names[(*femaleCount)++] = s->name;
	}
}

int main(void) {
	int size;
	int count = 0;
	int femaleCount = 0;

	printf("Enter the number of students: ");
	scanf("%d", &size);

	StudentList list = malloc(size * sizeof(Student));

	for (int i = 0; i < size; i++) {
		printf("\nStudent information #%d:\n", i + 1);
		addStudent(list, &count, getStudent());
	}

	NameList femaleNames = malloc(count * sizeof(Name));
	getFemaleNames(list, count, femaleNames, &femaleCount);

	femaleNames = realloc(femaleNames, femaleCount * sizeof(Name));

	if (femaleCount > 0) {
		printf("\nFemale students:\n");

		for (int i = 0; i < femaleCount; i++) {
			displayName(&femaleNames[i]);
		}
	}

	free(list);
	free(femaleNames);

	return 0;
}