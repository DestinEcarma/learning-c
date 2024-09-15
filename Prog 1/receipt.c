#include <stdio.h>

int main() {
	int qMilk, qFlour, qEgg;
	double cMilk, cFlour, cEgg;
	double amount;

	printf("%-22s", "Input milk quantity:");
	scanf("%d", &qMilk);
	printf("%-22s", "Input milk cost:");
	scanf("%lf", &cMilk);
	printf("%-22s", "Input flour quantity:");
	scanf("%d", &qFlour);
	printf("%-22s", "Input flour const:");
	scanf("%lf", &cFlour);
	printf("%-22s", "Input egg quantity:");
	scanf("%d", &qEgg);
	printf("%-22s", "Input egg const:");
	scanf("%lf", &cEgg);
	printf("%-22s", "Amount given:");
	scanf("%lf", &amount);

	double milkSubtotal = cMilk * qMilk;
	double flourSubtotal = cFlour * qFlour;
	double eggSubtotal = cEgg * qEgg;
	double totalCost = milkSubtotal + flourSubtotal + eggSubtotal;

	printf("\n%-20s%-20s%-20s%s\n", "Description", "Qty", "Unit Cost",
		   "Subtotal");
	printf("%-20s%3d%26.2lf%19.2lf\n", "Milk", qMilk, cMilk, milkSubtotal);
	printf("%-20s%3d%26.2lf%19.2lf\n", "Flour", qFlour, cFlour, flourSubtotal);
	printf("%-20s%3d%26.2lf%19.2lf\n", "Egg", qEgg, cEgg, eggSubtotal);
	printf("%68s\n", "--------");
	printf("%30s%38.2lf\n", "Total Cost", totalCost);
	printf("%32s%36.2lf\n", "Amount Given", amount);
	printf("%26s%42.2lf\n", "Change", amount - totalCost);

	return 0;
}