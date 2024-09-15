#include "utils.h"

#include <ctype.h>

Expression *parse(String input) {
	Expression *head = expressionNew();
	Expression *expression = head;

	int group = 0;

	for (char *ch = input; *ch; ch++) {
		if (isdigit(*ch)) {
			expression->operand = expression->operand * 10 + (*ch - '0');
		} else {
			int operator= getOperatorFromChar(*ch);

			if (operator) {
				expression->operator= operator;

				expression->right = expressionNew();
				expression->next = expression->right;

				expression = expression->right;
			}

			switch (*ch) {
			case '(':
				expression->group = ++group;
				expression->groupIndecies++;
				break;
			case ')':
				expression->group = -group;
				expression->groupIndecies--;
				break;
			}
		}
	}

	return head;
}

int getOperatorFromChar(char ch) {
	switch (ch) {
	case '+':
		return 1;
	case '-':
		return 2;
	case '*':
		return 3;
	case '/':
		return 4;
	case '^':
		return 5;
	default:
		return 0;
	}
}
