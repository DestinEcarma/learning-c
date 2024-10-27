#include <stdio.h>

#include "solver.h"
#include "sudoku.h"

int main(const int argc, const char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <state>\n", argv[0]);
		return 1;
	}

	Board *board = board_from(argv[1]);

	board_print(board);

	solve(board);

	board_print(board);

	return 0;
}
