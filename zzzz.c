#include <stdio.h>

int main(void) {
	int x = 1, *p1 = &x, **d1 = &p1, *p2 = &x, *p3, y = 1, *p4 = &y;

	p3 = *d1;
	printf("x = %d\n", x);
	++*p3;
	printf("x = %d\n", x);
	
	return 0;
}