#include <stdio.h>

int main(void) {
	printf("Itlog ni Noy AKIL!\n");
	printf("[1] #16 @ Php 15.00\n");
	printf("[2] #18 @ Php 22.50\n");
	printf("[3] penoy @ Php 13.00\n");

	int eggType, orders;
	float amount;

	do {
		printf("Enter your egg type: ");
		scanf("%d", &eggType);
	} while (!(eggType > 0 && eggType <= 3));

	printf("Enter total egg orders: ");
	scanf("%d", &orders);

	printf("Enter amount: ");
	scanf("%f", &amount);

	float price;

	switch (eggType) {
		case 1:
			price = 15.0;
			break;
		case 2:
			price = 22.5;
			break;
		case 3:
			price = 13.0;
			break;
	}

	float discount = 0, discountedPrice = 0;
	float totalCost = price * orders;
	int set = orders / 30 / 5;

	if (set == 1)
		discount = totalCost * 0.05;
	else if (set > 1)
		discount = totalCost * 0.1;

	if (discount)
		discountedPrice = totalCost - discount;

	float change = amount - (discountedPrice ? discountedPrice : totalCost);

	printf("\nSUMMARY\n");
	printf("Total Cost: Php %.2f\n", totalCost);
	printf("Discount: Php %.2f\n", discount);
	if (discountedPrice)
		printf("Discounted Price: Php %.2f\n", discountedPrice);
	printf("Change: ");
	if (change >= 0)
		printf("Php %.2f", change);
	else
		printf("(Php %.2f)", change * -1);

	return 0;
}