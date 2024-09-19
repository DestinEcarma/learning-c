#include <stdio.h>

#include "token.h"

TokenList newTokenList() {
	TokenList tokens = {{}, 0};

	return tokens;
}

void appendToken(TokenList *tokens, TokenType type, int value) {
	Token token = {type, value};

	tokens->tokens[tokens->count++] = token;
}

void displayTokenList(TokenList *tokens) {
	for (int i = 0; i < tokens->count; i++) {
		Token token = tokens->tokens[i];

		if (token.type == Operand) {
			printf("%d", token.value);
		} else {
			printf("%c", token.value);
		}

		if (i < tokens->count - 1) {
			printf(" ");
		}
	}

	printf("\n");
}
