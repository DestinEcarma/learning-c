#include <stdio.h>

int main(void) {
	int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	char symbols[][3] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
						 "XL", "X",	 "XI", "V",	 "IV", "I"};

	int num;
	int i = 0;

	scanf("%d", &num);

	while (num > 0) {
		int range = num / values[i];

		for (int j = 0; j < range; j++) {
			printf("%s", symbols[i]);
			num -= values[i];
		}

		i++;
	}

	return 0;
}
