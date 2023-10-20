#include <stdio.h>

int main(void) {
	int w, h;

	printf("Enter width of scyscraper: ");
	scanf("%d", &w);
	printf("Enter height of skyscraper: ");
	scanf("%d", &h);

	int half = w / 2;
	int perfectHalf = half * 2 == w;

	int x, y;

	for (y = 0; y < h; y++) {
		for (x = 0; x < w + 2; x++) {
			if (y > 0 && y < h - 1) {
				if (x > 0 && x < w + 1) printf("*");
				else printf(" ");
			} else {
				if (y == 0) {
					if (perfectHalf) {
						if (x == half || x == half + 1) printf("*");
						else printf(" ");
					} else {
						if (x == half + 1) printf("*");
						else printf(" ");
					}
				} else printf("*");
			}
		}

		printf("\n");
	}

	return 0;
}