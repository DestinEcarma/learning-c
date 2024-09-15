#include "expression.h"

#include <stdio.h>
#include <stdlib.h>

Expression *expressionNew() {
	Expression *expression = malloc(sizeof(Expression));

	expression->operand = 0;
	expression->operator= 0;
	expression->group = 0;
	expression->groupIndecies = 0;
	expression->right = NULL;
	expression->next = NULL;

	return expression;
}

void expressionDisplay(Expression *expression) {
	if (!expression) {
		return;
	}

	if (expression->groupIndecies > 0) {
		for (int i = 0; i < expression->groupIndecies; i++) {
			printf("(");
		}
	}

	printf("%.lf", expression->operand);

	if (expression->groupIndecies < 0) {
		for (int i = 0; i > expression->groupIndecies; i--) {
			printf(")");
		}
	}

	if (expression->right) {
		printf(" %c ", expressionGetOperator(expression));
		expressionDisplay(expression->right);
	}
}

char expressionGetOperator(Expression *expression) {
	switch (expression->operator) {
	case 1:
		return '+';
	case 2:
		return '-';
	case 3:
		return '*';
	case 4:
		return '/';
	case 5:
		return '^';
	default:
		return '\0';
	}
}

int expressionGetPrecedence(Expression *expression) {
	switch (expression->operator) {
	case 1: // +
	case 2: // -
		return 1;
	case 3: // *
	case 4: // /
		return 2;
	case 5: // ^
		return 3;
	default:
		return 0;
	}
}

Expression *expressionEvaluateGroup(Expression *expression, int group) {
	if (!expression) {
		return NULL;
	}

	if (expression->group != group) {
		return expression;
	}

	Expression *current = expression;

	double left = current->operand;
	double right;

	while (current->right) {
		current = current->right;

		if (current->group > 0 && current->group != group) {
			current = expressionEvaluateGroup(current, current->group);
		}
	}

	current->group = 0;
	return current;
}
