#include <stdio.h>
#include <string.h>

#include "sudoku.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))

Board *board_from(const char *state) {
	Board *board = malloc(sizeof(Board));

	if (board == NULL) {
		printf("Memory allocation failed\n");
		exit(1);
	}

	uint32_t len = MIN(strlen(state), TILES);

	memset(*board, '.', sizeof(Board));

	for (uint32_t square = 0; square < len; square++) {
		if (state[square] == '.') {
			continue;
		}

		Cell cell = {square / CELLS, square % CELLS};

		if (!board_add(board, cell, state[square] - '0')) {
			printf("Invalid board state\n");
			exit(1);
		}
	}

	return board;
}

bool board_is_solved(const Board *board) {
	for (uint32_t square = 0; square < TILES; square++) {
		if ((*board)[square] == '.') {
			return false;
		}
	}

	return true;
}

bool board_add(Board *board, Cell cell, uint32_t digit) {
	if (cell.row >= CELLS || cell.col >= CELLS || digit > 9) {
		return false;
	}

	uint32_t square = cell.row * CELLS + cell.col;

	const char prev = (*board)[square];

	(*board)[square] = digit + '0';

	if (!board_valid(board)) {
		(*board)[square] = prev;

		return false;
	}

	return true;
}

bool board_valid(const Board *board) {
	uint32_t row[CELLS] = {0};
	uint32_t col[CELLS] = {0};
	uint32_t cell[CELLS] = {0};

	for (uint32_t row_idx = 0; row_idx < CELLS; row_idx++) {
		for (uint32_t col_idx = 0; col_idx < CELLS; col_idx++) {
			uint32_t square = row_idx * CELLS + col_idx;

			if ((*board)[square] == '.') {
				continue;
			}

			uint32_t digit = (*board)[square] - '1';
			uint32_t mask = 1 << digit;
			uint32_t cell_idx = row_idx / 3 * 3 + col_idx / 3;

			if (row[row_idx] & mask || col[col_idx] & mask ||
				cell[cell_idx] & mask) {
				return false;
			}

			row[row_idx] |= mask;
			col[col_idx] |= mask;
			cell[cell_idx] |= mask;
		}
	}

	return true;
}

void board_print(const Board *board) {
	for (uint32_t row = 0; row < CELLS; row++) {
		for (uint32_t col = 0; col < CELLS; col++) {
			printf("%c ", (*board)[row * CELLS + col]);
		}

		printf("\n");
	}
}
