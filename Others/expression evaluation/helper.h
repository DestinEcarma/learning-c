#ifndef HELPER_H
#define HELPER_H

#include <stdbool.h>

#define MAX 100

typedef char String[MAX];

typedef enum { None, Low, Medium, High, Highest } Precedence;
typedef enum { Left, Right } Associativity;

bool isOperand(char);
bool isOperator(char);
bool isOpeningParenthesis(char);
bool isClosingParenthesis(char);

Precedence getPrecedence(char);
Associativity getAssociativity(char);

#endif
