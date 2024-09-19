#ifndef CONVERTER_H
#define CONVERTER_H

#include "helper.h"
#include "token.h"

TokenList infixToPostfix(String);

int evaluatePostfix(TokenList);

#endif
