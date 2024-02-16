#include<stdio.h>
#define MAX 100

int* sortElements(int arr[], int size);
void determineGaps(int arr[], int size);

int main(void) {
	// Start typing your C code here...
	// Use the given code lines and functions 
	int num;
	int i = 0;
	
	printf("Enter a number: ");
	scanf("%d", &num);
	
	printf("Foundation Codes:\n");

	int found[MAX];
	int count = 0;

	while (num > 0) {
		found[i++] = num % 10;
		count++;
		num /= 10;
	}

	for (i = 0; i < count; i++) {
		printf("%d\t", found[i]);
	}

	int *ptr1;
	
	// Show the sorted array elements
	ptr1 = sortElements(found, count);
	printf("\nSorted Codes:\n");
	
	for(i = 0; i < count; i++) {
		printf("%d\t", found[i]);
	}
	
	// Determine the gaps
	determineGaps(ptr1, count);
	
	return 0;
}

int* sortElements(int arr[], int size) {
	// Write your codes here for sorting the elements

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			int a = arr[j];
			int b = arr[j + 1];

			if (a > b) {
				arr[j] = b;
				arr[j + 1] = a;
			}
		}
	}
	
	return arr;
}

void determineGaps(int arr[], int size) {
	// Write your codes here for determining the gaps

	int gaps[MAX];
	int count = 0;
	int i;

	for (int gap = 0, j = 0; gap <= 9; gap++) {
		for (i = 0; i < size; i++) {
			if (gap == arr[i]) goto skip;
		}

		gaps[j++] = gap;
		count++;

		skip:
		continue;
	}
	
	printf("\nGaps:\n");
	for(i=0; i < count; i++) {
		printf("%d\t", gaps[i]);
	}
}