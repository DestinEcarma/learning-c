#include <stdbool.h>

#include "helper.h"

bool isOperand(char c) {
	return c >= '0' && c <= '9';
}

bool isOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool isOpeningParenthesis(char c) {
	return c == '(';
}

bool isClosingParenthesis(char c) {
	return c == ')';
}

Precedence getPrecedence(char c) {
	switch (c) {
		case '+':
		case '-':
			return Low;
		case '*':
		case '/':
			return Medium;
		case '^':
			return High;
		default:
			return None;
	}
}

Associativity getAssociativity(char c) {
	if (c == '^') {
		return Right;
	}

	return Left;
}
