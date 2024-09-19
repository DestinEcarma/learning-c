#include <stdio.h>

#include "dictionary.h"

int main() {
	Dictionary dictionary = newDictionary();

	int studentID = 23100411;

	dictionarySet(&dictionary, "FirstName", "Destin", 7);
	dictionarySet(&dictionary, "LastName", "Ecarma", 7);
	dictionarySet(&dictionary, "MiddleName", "Ripalda", 8);
	dictionarySet(&dictionary, "StudentID", &studentID, sizeof(int));

	printf("FirstName\t: %s\n",
		   (char *)dictionaryGet(&dictionary, "FirstName"));
	printf("LastName\t: %s\n", (char *)dictionaryGet(&dictionary, "LastName"));
	printf("MiddleName\t: %s\n",
		   (char *)dictionaryGet(&dictionary, "MiddleName"));
	printf("StudentID\t: %d\n",
		   *(int *)dictionaryGet(&dictionary, "StudentID"));

	printf("\nDelete Name\n");

	dictionaryRemove(&dictionary, "FirstName");
	dictionaryRemove(&dictionary, "LastName");
	dictionaryRemove(&dictionary, "MiddleName");

	printf("FirstName\t: %s\n",
		   (char *)dictionaryGet(&dictionary, "FirstName"));
	printf("LastName\t: %s\n", (char *)dictionaryGet(&dictionary, "LastName"));
	printf("MiddleName\t: %s\n",
		   (char *)dictionaryGet(&dictionary, "MiddleName"));
	printf("StudentID\t: %d\n",
		   *(int *)dictionaryGet(&dictionary, "StudentID"));

	printf("\nDelete StudentID\n");

	dictionaryRemove(&dictionary, "StudentID");

	printf("StudentID\t: %p\n", (int *)dictionaryGet(&dictionary, "StudentID"));

	return 0;
}
