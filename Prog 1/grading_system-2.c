#include <stdio.h>

int main(void) {
	int subjects, exams;

	printf("Input numer of Subjects: ");
	scanf("%d", &subjects);

	printf("Input number of Exams: ");
	scanf("%d", &exams);

	if (subjects == 0) goto exit;

	int len = subjects * exams;
	int sum = 0;

	int bestScore = 0, worstScore = 0;
	int bestIndex = 0, worstIndex = 0;

	for (int i = 1; i <= subjects; i++) {
		int sumSub = 0;

		for (int j = 1; j <= exams; j++) {
			int score;

			printf("Input Grade for Subject %d - Exam %d : ", i, j);
			scanf("%d", &score);

			sumSub += score;
		}

		sum += sumSub;

		if (i == 1 || sumSub > bestScore) {
			bestScore = sumSub;
			bestIndex = i;
		}

		if (i == 1 || sumSub < worstScore) {
			worstScore = sumSub;
			worstIndex = i;
		}
	}

	float avg = (float) sum / (float) (len * 100) * 100.0;

	printf("\n\nAverage Grade for %d Exams : %.f\n\n", len, avg);

	if (exams != 1) printf("Best Subject: Subject %d\n", bestIndex);
	else printf("No Best Subject\n");
	printf("Worst Subject: Subject %d\n\n", worstIndex);

	printf("%s this Semester", avg >= 75 ? "Passed" : "Failed");

	exit:
	return 0;
}