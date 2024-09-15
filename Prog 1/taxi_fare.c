#include <stdio.h>

int main() {
	int meters = 450;

	double fare = 40;

	if (meters > 250) {
		meters -= 250;

		while (meters > 0) {
			fare += 2.5;
			meters -= 200;
		}
	}

	printf("%lf", fare);

	return 0;
}