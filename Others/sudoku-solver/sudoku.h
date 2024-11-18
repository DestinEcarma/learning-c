#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdbool.h>
#include <stdlib.h>

#define TILES 81
#define CELLS 9

typedef unsigned char Digit;
typedef uint32_t Square;
typedef char Board[TILES];

Board *board_from(const char *state);

bool board_is_solved(const Board *board);

bool board_add(Board *board, Square square, Digit digit);

void board_set(Board *board, Square square, Digit value);

Digit board_get(const Board *board, Square square);

bool board_valid(const Board *board);

void board_print(const Board *board);

#endif
