#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX 10

typedef struct {
	int arr[MAX];
	int count;
} ArrayList;

bool insertRear(ArrayList *list, int item);
bool insertFront(ArrayList *list, int item);
bool insertAt(ArrayList *list, int item, int loc);
bool deleteRear(ArrayList *list);
bool deleteFront(ArrayList *list);
void display(ArrayList list);

// bool insertRear1(int arr[], int *count, int item) {
//     if(*count < MAX) {
//         arr[(*count)++] = item;
//         return true;
//     }
//     return false;
// }

int main() {
	ArrayList myList;
	myList.count = 0;

	display(myList);
	insertRear(&myList, 5);
	display(myList);
	insertFront(&myList, 2);
	display(myList);
	insertRear(&myList, 6);
	display(myList);
	insertFront(&myList, 5);
	display(myList);
	insertFront(&myList, 1);
	display(myList);
	insertAt(&myList, 100, 3);
	display(myList);
	deleteRear(&myList);
	display(myList);
	insertRear(&myList, 1000);
	display(myList);
	deleteFront(&myList);
	display(myList);
	deleteFront(&myList);
	display(myList);
	deleteFront(&myList);
	display(myList);

	return 0;
}

bool insertRear(ArrayList *list, int item) {
	if (list->count < MAX) { //(*list).count < MAX
		list->arr[(list->count)++] = item;
		return true;
	}
	return false;
}

bool insertFront(ArrayList *list, int item) { return insertAt(list, item, 0); }

bool insertAt(ArrayList *list, int item, int loc) {
	if (list->count < MAX) {
		memmove(list->arr + loc + 1, list->arr + loc,
				(list->count - loc) * sizeof(int));
		list->arr[loc] = item;
		(list->count)++;
		return true;
	}
	return false;
}

bool deleteRear(ArrayList *list) {
	if (list->count > 0) { //(*list).count < MAX
		(list->count)--;
		return true;
	}
	return false;
}

bool deleteFront(ArrayList *list) {
	if (list->count > 0) {
		int count = list->count - 1;
		memmove(list->arr, list->arr + 1, count * sizeof(int));
		(list->count)--;
		return true;
	}
	return false;
}

void display(ArrayList list) {
	printf("{");
	for (int i = 0; i < list.count; ++i) {
		printf("%d", list.arr[i]);
		if (i < list.count - 1) {
			printf(", ");
		}
	}
	printf("}\n");
}
