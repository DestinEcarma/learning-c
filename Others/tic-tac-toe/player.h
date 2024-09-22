#ifndef PLAYER_H
#define PLAYER_H

#define PLAYER_SIZE 2

typedef enum {
	PLAYER_X,
	PLAYER_O,
	PLAYER_NONE,
} Player;

char player_char(Player player);

#endif
