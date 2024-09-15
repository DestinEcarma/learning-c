#ifndef ACT2_23100411_ECARMA_FUNCTIONS_H
#define ACT2_23100411_ECARMA_FUNCTIONS_H
#include <stdbool.h>
#include <stddef.h>

// ctype Library
bool my_isalnum(int c);
bool my_isalpha(int c);
bool my_isdigit(int c);
bool my_islower(int c);
bool my_isspace(int c);
bool my_isupper(int c);
int my_tolower(int c);
int my_toupper(int c);

// string Library
size_t my_strlen(const char *str);
char *my_strcat(char *dest, const char *src);
char *my_strcpy(char *dest, const char *src);
int my_strcmp(const char *str1, const char *str2);

// counter
int my_counterDigits(const char *str);
#endif
