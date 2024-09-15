#include <stdlib.h>

#include "converter.h"
#include "helper.h"
#include "token.h"

TokenList infixToPostfix(String infix) {
	TokenList tokens = newTokenList();

	char stack[MAX];
	int stackTop = -1;

	for (char *ch = infix; *ch != '\0'; ch++) {
		char c = *ch;

		if (isOperand(c) || (c == '-' && isOperand(*(ch + 1)))) {
			appendToken(&tokens, Operand, atoi(ch));

			while (isOperand(*(ch + 1))) {
				ch++;
			}
		} else if (isOpeningParenthesis(c)) {
			stack[++stackTop] = c;
		} else if (isClosingParenthesis(c)) {
			while (stackTop >= 0 && !isOpeningParenthesis(stack[stackTop])) {
				appendToken(&tokens, Operator, stack[stackTop--]);
			}

			stackTop--;
		} else if (isOperator(c)) {
			while (stackTop >= 0 &&
				   (getPrecedence(c) < getPrecedence(stack[stackTop]) ||
					(getPrecedence(c) == getPrecedence(stack[stackTop]) &&
					 getAssociativity(c) == Left))) {
				appendToken(&tokens, Operator, stack[stackTop--]);
			}

			stack[++stackTop] = c;
		}
	}

	while (stackTop >= 0) {
		appendToken(&tokens, Operator, stack[stackTop--]);
	}

	return tokens;
}

int evaluatePostfix(TokenList postfix) {
	int stack[postfix.count] = {};
	int stackTop = -1;

	for (int i = 0; i < postfix.count; i++) {
		stack[i] = 0;
	}

	for (int i = 0; i < postfix.count; i++) {
		Token token = postfix.tokens[i];

		if (token.type == Operand) {
			stack[++stackTop] = token.value;
		} else {
			int b = stack[stackTop--];
			int a = stack[stackTop--];

			switch (token.value) {
			case '+':
				stack[++stackTop] = a + b;
				break;
			case '-':
				stack[++stackTop] = a - b;
				break;
			case '*':
				stack[++stackTop] = a * b;
				break;
			case '/':
				stack[++stackTop] = a / b;
				break;
			case '^':
				stack[++stackTop] = a ^ b;
				break;
			}
		}
	}

	return stack[stackTop];
}
