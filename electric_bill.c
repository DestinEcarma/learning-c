#include <stdio.h>

int main() {
	// Quantity
	int qAircon, qFan, qTV, qRef;
	// Hours/Day
	int hAircon, hFan, hTV, hRef;

	printf("%-15s%-9s%s\n", "Description", "Qty", "Hrs/Day");
	printf("%-15s", "Aircon");
	scanf("%d%d", &qAircon, &hAircon);
	printf("%-15s", "Fan");
	scanf("%d%d", &qFan, &hFan);
	printf("%-15s", "TV");
	scanf("%d%d", &qTV, &hTV);
	printf("%-15s", "Refrigerator");
	scanf("%d%d", &qRef, &hRef);

	printf("\nSummary:");
	printf("\n%-15s%-15s%s", "Description", "Quantity", "Hrs/Day");
	printf("\n%-15s%8d%14d", "Aircon", qAircon, hAircon);
	printf("\n%-15s%8d%14d", "Fan", qFan, hFan);
	printf("\n%-15s%8d%14d", "TV", qTV, hTV);
	printf("\n%-15s%8d%14d", "Refrigerator", qRef, hRef);

	int airconHours = (qAircon * hAircon) * 30;
	int fanHours = (qFan * hFan) * 30;
	int tvHours = (qTV * hTV) * 30;
	int refHours = (qRef * hRef) * 30;
	int totalUsage = airconHours + fanHours + tvHours + refHours;

	int airconConsumption = 261 * airconHours;
	int fanConsumption = 12 * fanHours;
	int tvConsumption = 27 * tvHours;
	int refConsumption = 117 * refHours;
	int totalConsumption = airconConsumption + fanConsumption + tvConsumption + refConsumption;

	double basicCharges = ((totalConsumption > 100000) ? 100000 : totalConsumption) * 0.05;
	double excessCharges = (totalConsumption > 100000) ? ((totalConsumption - 100000) * 0.03) : 0;
	double totalCharges = excessCharges + basicCharges;

	printf("\n\n%-25s%20d", "Total Usage (hrs):", totalUsage);
	printf("\n%-25s%20d", "Total Consumption (kwh):", totalConsumption);
	printf("\n%-25s%s%15.2lf", "Total Charges:", "Pesos", totalCharges);

	return 0;
}