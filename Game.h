#ifndef GAME_H
#define GAME_H

#include "constants.h"
#include "Player.h"

class Game {
public:
	void play(int results[]);
	bool gameEnd();
private:
	Player p[NUM_OF_PLAYERS];
};

#endif