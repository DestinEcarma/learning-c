#include <stdbool.h>
#include <stdio.h>

#include "solver.h"
#include "sudoku.h"

#define MAX_CANDIDATES 9

typedef struct {
	uint32_t square;
	uint32_t size;
	uint32_t candidates[MAX_CANDIDATES];
} HeuristicValues;

bool is_valid_move(Board *board, Cell cell, uint32_t digit) {
	uint32_t square = cell.row * CELLS + cell.col;
	unsigned char prev_char = (*board)[square];

	(*board)[square] = digit + '0';
	bool result = board_valid(board);
	(*board)[square] = prev_char;

	return result;
}

HeuristicValues get_heuristic_values(Board *board, uint32_t square) {
	HeuristicValues values = {square, 0, {}};

	for (uint32_t digit = 1; digit <= MAX_CANDIDATES; digit++) {
		Cell cell = {square / CELLS, square % CELLS};

		if (is_valid_move(board, cell, digit)) {
			values.candidates[values.size++] = digit;
		}
	}

	return values;
}

bool solve(Board *board) {
	if (board_is_solved(board)) {
		return true;
	}

	HeuristicValues lowest = {0, MAX_CANDIDATES + 1, {}};

	for (uint32_t square = 0; square < TILES; square++) {
		if ((*board)[square] != '.') {
			continue;
		}

		HeuristicValues values = get_heuristic_values(board, square);

		if (values.size < lowest.size) {
			lowest = values;
		}
	}

	if (lowest.size == 0) {
		return false;
	}

	Cell cell = {lowest.square / CELLS, lowest.square % CELLS};
	printf("Square: %d, Candidates: %d\n", lowest.square, lowest.size);

	for (uint32_t i = 0; i < lowest.size; i++) {
		unsigned char prev_char = (*board)[lowest.square];

		board_print(board);
		printf("\n");
		board_add(board, cell, lowest.candidates[i]);

		if (solve(board) == false) {
			(*board)[lowest.square] = prev_char;
		}
	}

	return true;
}
