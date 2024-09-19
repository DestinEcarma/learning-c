#include <stdio.h>

#include "converter.h"
#include "token.h"

int main() {
	String infix;

	printf("Infix: ");
	fgets(infix, 100, stdin);

	TokenList postfix = infixToPostfix(infix);

	printf("Postfix: ");
	displayTokenList(&postfix);

	int result = evaluatePostfix(postfix);

	printf("Result: %d\n", result);

	return 0;
}
