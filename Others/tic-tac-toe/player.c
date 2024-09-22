#include "player.h"

char player_char(Player player) {
	switch (player) {
		case PLAYER_X:
			return 'X';
		case PLAYER_O:
			return 'O';
		default:
			return ' ';
	}
}
