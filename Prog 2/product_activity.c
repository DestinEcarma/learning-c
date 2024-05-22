#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

int MONTH_DAYS[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

typedef char String[20];

typedef struct {
	int day;
	int month;
	int year;
} MyDate;

typedef struct {
	int id;
	String name;
	MyDate exDate;
	float price;
} Product;

typedef struct {
	Product prods[SIZE];
	int count;
} ProductListStatic;

typedef struct {
	Product *prods;
	int count;
} ProductListDynamic;

int isLeapYear(int year) {
	return (!(year % 4) && year % 100) || !(year % 400);
}

int getDaysOfMonth(int month, int year) {
	if (month == 2 && isLeapYear(year)) return 29;
	return MONTH_DAYS[month];
}

int dateDifference(MyDate a, MyDate b) {
	int daysA = a.day + (a.month - 1) * getDaysOfMonth(a.month, a.year) + a.year * 365;
	int daysB = b.day + (b.month - 1) * getDaysOfMonth(b.month, b.year) + b.year * 365;

	if (isLeapYear(a.year) && a.month < 3) daysA--;
	if (isLeapYear(b.year) && b.month > 2) daysB++;

	return daysB - daysA;
}

void printStaticList(ProductListStatic *list) {
	printf("ID\tName\tExpiry\t\tPrice\n");

	for (int i = 0; i < list->count; i++) {
		Product temp = list->prods[i];

		printf("%d\t%s\t%02d-%02d-%04d\t%.2f\n", temp.id, temp.name, temp.exDate.day, temp.exDate.month, temp.exDate.year, temp.price);
	}

	printf("\n");
}

void printDynamicList(ProductListDynamic *list) {
	printf("ID\tName\tExpiry\t\tPrice\n");

	for (int i = 0; i < list->count; i++) {
		Product temp = list->prods[i];

		printf("%d\t%s\t%02d-%02d-%04d\t%.2f\n", temp.id, temp.name, temp.exDate.day, temp.exDate.month, temp.exDate.year, temp.price);
	}

	printf("\n");
}

ProductListDynamic *filter(ProductListStatic *list, MyDate expiry) {
	ProductListDynamic *filtered = malloc(sizeof(ProductListDynamic));

	filtered->prods = malloc(list->count * sizeof(Product));
	filtered->count = 0;

	for (int i = 0; i < list->count; i++) {
		if (dateDifference(list->prods[i].exDate, expiry) < 0) continue;

		Product temp = list->prods[i];
		int j = 0;

		for (; j < filtered->count; j++) {
			if (dateDifference(temp.exDate, filtered->prods[j].exDate) > 0) break;
		}

		memmove(filtered->prods + j + 1, filtered->prods + j, (filtered->count - j) * sizeof(Product));
		memmove(list->prods + i, list->prods + i + 1, (list->count - i - 1) * sizeof(Product));

		filtered->prods[j] = temp;
		filtered->count++;

		list->count--;

		if (j >= i) i--;
	}

	return filtered;
}

int main() {
	ProductListStatic staticList = {{
										(Product){1, "Test01", {2, 4, 2021}, 0},
										(Product){2, "Test02", {2, 4, 2021}, 0},
										(Product){3, "Test03", {2, 4, 2021}, 0},
										(Product){4, "Test04", {2, 4, 2020}, 0},
										(Product){5, "Test05", {2, 4, 2024}, 0},
										(Product){6, "Test06", {2, 4, 2024}, 0},
										(Product){7, "Test07", {2, 4, 2024}, 0},
										(Product){8, "Test08", {2, 4, 2024}, 0},
										(Product){9, "Test09", {2, 4, 2024}, 0},
										(Product){10, "Test10", {2, 4, 2019}, 0},
									},
									SIZE};

	ProductListDynamic *filtered = filter(&staticList, (MyDate){2, 2, 2024});

	printStaticList(&staticList);

	printf("Expired Product:\n");
	printDynamicList(filtered);

	return 0;
}