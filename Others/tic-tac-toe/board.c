#include <stdio.h>
#include <stdlib.h>

#include "board.h"
#include "player.h"

// Local Implementations

// clang-format off
const unsigned int WINNING_MASKS[8] = {
	0b111000000,
	0b000111000,
	0b000000111,
	0b100100100,
	0b010010010,
	0b001001001,
	0b100010001,
	0b001010100,
};
// clang-format on

Player board_get_player(Board *board, int row, int col) {
	int index = row * GRID_SIZE + col;

	if (board->player_grid[PLAYER_X] >> index & 1) {
		return PLAYER_X;
	} else if (board->player_grid[PLAYER_O] >> index & 1) {
		return PLAYER_O;
	}

	return PLAYER_NONE;
}

// Global Implementations

Board new_board() {
	return (Board){{}, rand() % PLAYER_SIZE};
}

void board_display(Board *board) {
	printf("+———+———+———+\n");

	for (int row = 0; row < GRID_SIZE; row++) {
		for (int col = 0; col < GRID_SIZE; col++) {
			Player player = board_get_player(board, row, col);

			printf("| %c ", player_char(player));

			if (col == GRID_SIZE - 1) {
				printf("|\n");
			}
		}

		printf("+———+———+———+\n");
	}
}

bool board_play(Board *board, Player player, size_t position) {
	if (player != board->turn) {
		return false;
	}

	if (position >= GRID_SIZE * GRID_SIZE) {
		return false;
	}

	int index = 1 << position;

	if (board->player_grid[PLAYER_X] >> position & 1 ||
		board->player_grid[PLAYER_O] >> position & 1) {
		return false;
	}

	board->player_grid[player] |= index;
	board->turn = (player + 1) % PLAYER_SIZE;

	return true;
}

GameStatus board_game_status(Board *board) {
	for (int i = 0; i < 8; i++) {
		if ((board->player_grid[PLAYER_X] & WINNING_MASKS[i]) ==
			WINNING_MASKS[i]) {
			return PLAYER_X_WIN;
		} else if ((board->player_grid[PLAYER_O] & WINNING_MASKS[i]) ==
				   WINNING_MASKS[i]) {
			return PLAYER_O_WIN;
		}
	}
	// clang-format off
	if ((
		board->player_grid[PLAYER_X] |
		board->player_grid[PLAYER_O]
	) == 0b111111111) {
		return PLAYER_DRAW;
	}
	// clang-format on

	return PLAYER_CONTINUE;
}
