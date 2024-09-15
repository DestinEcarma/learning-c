#ifndef TOKEN_H
#define TOKEN_H

#include <stdbool.h>

#include "helper.h"

typedef enum { Operand, Operator } TokenType;

typedef struct {
	TokenType type;
	int value;
} Token;

typedef struct {
	Token tokens[MAX];
	int count;
} TokenList;

TokenList newTokenList();

void appendToken(TokenList *, TokenType, int);

void displayTokenList(TokenList *);

#endif
