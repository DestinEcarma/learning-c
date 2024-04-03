#include <stdio.h>
#include <stdlib.h>

#include "def.h"
#include "expression.h"
#include "utils.h"

int main(void) {
	String expressionStr;

	printf("Enter an expression: ");
	fgets(expressionStr, sizeof(expressionStr), stdin);

	Expression *expression = parse(expressionStr);

	expressionDisplay(expression);
}