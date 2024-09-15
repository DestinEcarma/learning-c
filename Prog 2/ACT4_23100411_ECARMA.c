#include <stdio.h>
#include <time.h>

const char *MONTHS[12] = {
	"JAN", "FEB", "MAR", "APR", "MAY", "JUN",
	"JUL", "AUG", "SEP", "OCT", "NOV", "DEC",
};

const int DAYS[12] = {
	31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
};

const char *ZODIAC_SIGNS[12] = {
	"Aries", "Taurus",	 "Gemini",		"Cancer",	   "Leo",	   "Virgo",
	"Libra", "Scorpius", "Sagittarius", "Capricornus", "Aquarius", "Pisces",
};

const int ZODIAC_MONTHS[12][2] = {
	{3, 4},	 {4, 5},   {5, 6},	 {6, 7},  {7, 8}, {8, 9},
	{9, 10}, {10, 11}, {11, 12}, {12, 1}, {1, 2}, {2, 3},
};

const int ZODIAC_DAYS[12][2] = {
	{21, 19}, {20, 20}, {21, 21}, {22, 22}, {23, 22}, {23, 22},
	{23, 23}, {24, 21}, {22, 21}, {22, 19}, {20, 18}, {19, 20},
};

typedef struct {
	int day;
	int month;
	int year;
} Date;

int isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int isValidDate(Date date) {
	if (date.year < 0)
		return 0;
	if (date.month < 1 || date.month > 12)
		return 0;
	if (date.day < 1)
		return 0;

	int maxDays = DAYS[date.month - 1];

	if (date.month == 2 && isLeapYear(date.year))
		maxDays++;
	return date.day <= maxDays;
}

int getZodiacSign(Date date) {
	for (int i = 0; i < 12; i++) {
		int startMonth = ZODIAC_MONTHS[i][0];
		int endMonth = ZODIAC_MONTHS[i][1];
		int startDay = ZODIAC_DAYS[i][0];
		int endDay = ZODIAC_DAYS[i][1];

		if (date.month == startMonth && date.day >= startDay)
			return i;
		if (date.month == endMonth && date.day <= endDay)
			return i;
	}

	return -1;
}

int getAge(Date date) {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	int age = tm.tm_year + 1900 - date.year;

	if (tm.tm_mon < date.month) {
		age--;
	} else if (tm.tm_mon == date.month && tm.tm_mday < date.day) {
		age--;
	}

	return age;
}

void printDate(Date date) {
	printf("%02d %s %04d\n", date.day, MONTHS[date.month - 1], date.year);
}

int main(void) {
	Date date;

	printf("Enter your birth date (MM-DD-YYYY): ");
	scanf("%d-%d-%d", &date.month, &date.day, &date.year);

	if (!isValidDate(date)) {
		printf("Invalid date\n");
		return 1;
	}

	printf("You were born on ");
	printDate(date);

	printf("You are %d years old\n", getAge(date));
	printf("Your zodiac sign is %s\n", ZODIAC_SIGNS[getZodiacSign(date)]);

	return 0;
}