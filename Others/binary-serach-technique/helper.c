#include "helper.h"

int binary_search(List list, int size, int needle) {
	int result = -1;

	int low = 0;
	int high = size - 1;

	while (result == -1 && low <= high) {
		int mid = (low + high) / 2;

		if (list[mid] == needle) {
			result = mid;
		} else if (list[mid] < needle) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}

	return result;
}
