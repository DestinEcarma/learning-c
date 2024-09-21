#ifndef READ_CLI_H
#define READ_CLI_H

#include <stdio.h>

// Read a string from the command line, this function removes `\n` character.
char *readCliString(const size_t length);

// Read a character from the command line.
char readCliChar();

// Read an integer from the command line.
int readCliInt();

// Read a float from the command line.
float readCliFloat();

// Read a double from the command line.
double readCliDouble();

#endif
