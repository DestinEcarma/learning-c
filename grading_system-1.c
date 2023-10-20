#include <stdio.h>

int main() {
	double exercise1, exercise2, exercise3;
	double midterm, final;

	printf("Laboratory Exercise #1: ");
	scanf("%lf", &exercise1);
	printf("Laboratory Exercise #2: ");
	scanf("%lf", &exercise2);
	printf("Laboratory Exercise #3: ");
	scanf("%lf", &exercise3);
	printf("Midterm Exam: ");
	scanf("%lf", &midterm);
	printf("Final Exam: ");
	scanf("%lf", &final);

	double exercisesScores = exercise1 + exercise2 + exercise3;

	double exerciseOverall = (exercisesScores / 150.0) * 0.3;
	double midtermOverall = (midterm / 100.0) * 0.3;
	double finalOverall = (final / 100.0) * 0.4;

	double finalGrade = (exerciseOverall + midtermOverall + finalOverall) * 100;

	printf("\nCourse: \tProgramming 1");
	printf("\nExercises:");
	printf("\n\tLab Exercise 1:%12.lf/50", exercise1);
	printf("\n\tLab Exercise 2:%12.lf/50", exercise2);
	printf("\n\tLab Exercise 3:%12.lf/50", exercise3);
	printf("\nExams:");
	printf("\n\tMidterm Exam: \t%10.lf/100", midterm);
	printf("\n\tFinal Exam: \t%10.lf/100", final);
	printf("\n\nFinal Grade: \t\t\t%5.lf%%", finalGrade);

	if (finalGrade >= 70)
		printf("\nStatus: \t\t\tPassed");
	else
		printf("\nStatus: \t\t\tFailed");

	return 0;
}