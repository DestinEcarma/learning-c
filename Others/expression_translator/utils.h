#ifndef UTILS_H
#define UTILS_H

#include "def.h"
#include "expression.h"

Expression *parse(String input);

int getOperatorFromChar(char ch);

#endif