#include <stdbool.h>

#include "solver.h"
#include "sudoku.h"

#define MAX_CANDIDATES 9

typedef struct {
	uint32_t square;
	uint32_t size;
	unsigned char candidates[MAX_CANDIDATES];
} HeuristicValues;

bool is_valid_move(Board *board, uint32_t square, unsigned char digit) {
	unsigned char prev_char = (*board)[square];

	board_set(board, square, digit);
	bool result = board_valid(board);
	board_set(board, square, prev_char);

	return result;
}

HeuristicValues get_heuristic_values(Board *board, uint32_t square) {
	HeuristicValues values = {square, 0, {}};

	for (unsigned char digit = '1'; digit <= '9'; digit++) {
		if (is_valid_move(board, square, digit)) {
			values.candidates[values.size++] = digit;
		}
	}

	return values;
}

void solve(Board *board) {
	HeuristicValues lowest = {0, MAX_CANDIDATES + 1, {}};

	for (uint32_t square = 0; square < TILES; square++) {
		if ((*board)[square] != '.') {
			continue;
		}

		HeuristicValues values = get_heuristic_values(board, square);

		if (values.size > 0 && values.size < lowest.size) {
			lowest = values;
		}
	}

	if (lowest.size <= MAX_CANDIDATES) {
		for (uint32_t i = 0; i < lowest.size; i++) {
			board_set(board, lowest.square, lowest.candidates[i]);
			solve(board);

			if (board_is_solved(board)) {
				return;
			}

			board_set(board, lowest.square, '.');
		}
	}
}

void _solve_all(Board *board, uint32_t square) {
	if (square == TILES) {
		board_print(board);
		return;
	}

	if ((*board)[square] != '.') {
		_solve_all(board, square + 1);
		return;
	}

	for (unsigned char digit = '1'; digit <= '9'; digit++) {
		if (board_add(board, square, digit)) {
			_solve_all(board, square + 1);
			board_set(board, square, '.');
		}
	}
}
