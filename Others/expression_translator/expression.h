#ifndef EXPRESSION_H
#define EXPRESSION_H

typedef struct Expression {
	double operand;
	int operator;
	int group;
	int groupIndecies;
	struct Expression *right;
	struct Expression *next;
} Expression;

Expression *expressionNew();

void expressionDisplay(Expression *expression);

char expressionGetOperator(Expression *expression);

int expressionGetPrecedence(Expression *expression);

Expression *expressionEvaluateGroup(Expression *expression, int group);

#endif