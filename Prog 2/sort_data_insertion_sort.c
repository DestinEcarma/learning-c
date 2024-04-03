#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

typedef struct temp {
	char fname[20];
	char lname[20];
	char program[20];
	int age;
} Info;

Info *sortByProgramAsc(Info var[MAX]) {
	Info *arr = malloc(MAX * sizeof(Info));

	memcpy(arr, var, MAX * sizeof(Info));

	for (int i = 1; i < MAX; i++) {
		Info temp = arr[i];
		int j = i - 1;

		while (j >= 0 && strcmp(arr[j].program, temp.program) > 0) j--;

		memmove(arr + j + 2, arr + j + 1, (i - j - 1) * sizeof(Info));
		arr[j + 1] = temp;
	}

	return arr;
}

Info *sortByLastNameAsc(Info var[MAX]) {
	Info *arr = malloc(MAX * sizeof(Info));

	memcpy(arr, var, MAX * sizeof(Info));

	for (int i = 1; i < MAX; i++) {
		Info temp = arr[i];
		int j = i - 1;

		while (j >= 0 && strcmp(arr[j].lname, temp.lname) > 0) j--;

		memmove(arr + j + 2, arr + j + 1, (i - j - 1) * sizeof(Info));
		arr[j + 1] = temp;
	}

	return arr;
}

void printInfo(Info *var) {
	printf("%s\t%s\t\t%s\t%d\n", var->fname, var->lname, var->program, var->age);
}

void printInfoList(Info var[MAX]) {
	for (int i = 0; i < MAX; i++) {
		printInfo(&var[i]);
	}

	printf("\n");
}

int main(void) {
	Info arr[MAX] = {{"Chris", "Maderazo", "BSCOMPE", 51},
					 {"John", "Duterte", "BSIT", 30},
					 {"asdf", "qwer", "BSCS", 19},
					 {"wert", "sdfg", "BSIT", 20},
					 {"sdfg", "hdfgh", "BSCS", 30}};

	Info *var2 = sortByProgramAsc(arr);
	printInfoList(var2);

	Info *var3 = sortByLastNameAsc(arr);
	printInfoList(var3);

	free(var2);
	free(var3);

	return 0;
}