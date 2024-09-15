#include <stdio.h>

int main(void) {
	int num;

	printf("Enter your number: ");
	scanf("%d", &num);

	int binary = 0;
	int temp = 0;
	int len = 0;
	int placement = 1;

	for (int i = 0; i < 16; i++) {
		if ((num & (1 << i)) != 0) {
			binary += placement;
			temp |= 1 << i;
		}

		placement *= 10;
		len++;
		if (temp == num)
			break;
	}

	printf("The value of your soul is %d.\n", binary);

	int half = len / 2;
	int symmetric = 1;

	for (int i = 1; i <= half; i++) {
		int left = (num & (1 << (i - 1))) != 0;
		int right = (num & (1 << (len - i))) != 0;

		if (left != right) {
			symmetric = 0;
			break;
		}
	}

	printf("%s", symmetric ? "You are worthy my child."
						   : "Ahh, you are filty. Be gone.");

	return 0;
}