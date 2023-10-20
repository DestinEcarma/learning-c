#include <stdio.h>

int main(void) {
	int num;

	printf("Enter a number: ");
	scanf("%d", &num);

	for (int i = 1; i <= num; i++) {
		if (num % i) continue;

		int isComposite = 0;

		for (int j = 2; j <= i / 2; j++) {
			if (!(i % j)) {
				isComposite = 1;
				break;
			}
		}

		if (isComposite) printf("{%d} ", i);
		else printf("%d ", i);
	}
	
	return 0;
}