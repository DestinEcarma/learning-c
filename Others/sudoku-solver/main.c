#include "solver.h"
#include "sudoku.h"

int main() {
	/*Board *board = board_from("53..7....6..195....98....6.8...6...34..8.3.."*/
	/*						  "17...2...6.6....28....419..5....8..79");*/
	Board *board = board_from("1");

	board_print(board);

	solve(board);

	board_print(board);

	return 0;
}
