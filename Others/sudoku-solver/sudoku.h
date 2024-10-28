#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdbool.h>
#include <stdlib.h>

#define TILES 81
#define CELLS 9

typedef char Board[TILES];

Board *board_from(const char *state);

bool board_is_solved(const Board *board);

bool board_add(Board *board, uint32_t square, unsigned char digit);

void board_set(Board *board, uint32_t square, unsigned char value);

bool board_valid(const Board *board);

void board_print(const Board *board);

#endif
