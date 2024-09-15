#include <math.h>
#include <stdio.h>

int main() {
	int num;

	printf("Enter an integer: ");
	scanf("%d", &num);

	int squareRoot = sqrt(num);
	int cubeRoot = cbrt(num);

	int isPerfectSquare = (squareRoot * squareRoot) == num;
	int isPerfectCube = (cubeRoot * cubeRoot * cubeRoot) == num;

	if (isPerfectSquare && isPerfectCube) {
		printf("Perfect in every way");
	} else if (isPerfectCube && (num % 2) == 0) {
		printf("Perfect in even cubes");
	} else if (isPerfectCube && (num % 3) == 0) {
		printf("Perfect in an odd way");
	} else {
		printf("Nothing special");
	}

	return 0;
}