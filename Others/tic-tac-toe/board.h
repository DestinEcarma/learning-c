#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>
#include <stdlib.h>

#include "player.h"

#define GRID_SIZE 3

typedef struct {
	Player player_grid[PLAYER_SIZE];
	Player turn;
} Board;

typedef enum {
	PLAYER_X_WIN,
	PLAYER_O_WIN,
	PLAYER_DRAW,
	PLAYER_CONTINUE,
} GameStatus;

Board new_board();

void board_display(Board *board);

bool board_play(Board *board, Player player, size_t position);

GameStatus board_game_status(Board *board);

#endif
