#include <stdio.h>
#include <stdarg.h>

extern void printlnf(const char *const _Format, ...) {
	va_list args;
	va_start(args, _Format);
	vprintf(_Format, args);
	va_end(args);
	printf("\n");
}