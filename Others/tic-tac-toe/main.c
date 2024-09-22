#include <ctype.h>
#include <stdio.h>

#include "board.h"

int main() {
	printf("Welcome to Tic-Tac-Toe!\n");

	while (true) {
		// clang-format off
		printf("\nTo play, enter a number from 1 to 9 based on the following grid:\n");
		printf("+———+———+———+\n");
		printf("| 1 | 2 | 3 |\n");
		printf("+———+———+———+\n");
		printf("| 4 | 5 | 6 |\n");
		printf("+———+———+———+\n");
		printf("| 7 | 8 | 9 |\n");
		printf("+———+———+———+\n");
		// clang-format on

		Board board = new_board();

		while (board_game_status(&board) == PLAYER_CONTINUE) {
			Player player = board.turn;
			char position = 'A';

			do {
				// clang-format off
				printf("\nPlayer %c, enter a position (1-9): ", player_char(player));
				scanf(" %c", &position);
				// clang-format on
			} while (!board_play(&board, player, position - '1'));

			board_display(&board);
		}

		GameStatus status = board_game_status(&board);

		if (status == PLAYER_X_WIN) {
			printf("\nPlayer X wins!\n");
		} else if (status == PLAYER_O_WIN) {
			printf("\nPlayer O wins!\n");
		} else {
			printf("\nIt's a draw!\n");
		}

		char play_again;
		printf("\nPlay again? (y/n): ");
		scanf(" %c", &play_again);

		if (tolower(play_again) != 'y') {
			break;
		}
	}

	return 0;
}
