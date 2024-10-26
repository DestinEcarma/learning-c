#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdbool.h>
#include <stdlib.h>

#define TILES 81
#define CELLS 9

typedef char Board[TILES];

typedef struct {
	uint32_t row;
	uint32_t col;
} Cell;

Board *board_from(const char *state);

bool board_is_solved(const Board *board);

bool board_add(Board *board, Cell cell, uint32_t digit);

bool board_valid(const Board *board);

void board_print(const Board *board);

#endif
