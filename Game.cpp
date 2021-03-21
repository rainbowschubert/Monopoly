#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>
#include "constants.h"
#include "Game.h"
#include "Player.h"

using namespace std;

void Game::play(int results[]) {
	srand(time(NULL));
	int roll1, roll2;
	for (int i = 0; i < 100; i++) {//replace with while (!gameEnd())
		for (int j = 0; j < NUM_OF_PLAYERS; j++) {
			if (i > 0 && (!p[j].inJail() || p[j].getJailTurn() == 1)) results[p[j].getPosition()]++;
			roll1 = rand() % 6 + 1;
			roll2 = rand() % 6 + 1;
			if (p[j].inJail()) {//rolling doubles in jail
				//if player in jail, player can choose doubles, get out of jail free card, or pay 50
				if (p[j].getOutOfJailFreeCard()) {
					int temp = rand() % 3;
					if (temp == 0) p[j].useJailCard();
					else if (temp == 1) {
						if (roll1 == roll2) p[j].getOutOfJail();
						else if (roll1 != roll2 && p[j].getJailTurn() < 3) {
							p[j].setJailTurn(p[j].getJailTurn() + 1);
							break;
						}
						else if (roll1 != roll2 && p[j].getJailTurn() == 3) {
							p[j].setMoney(p[j].getMoney() - 50);
							p[j].getOutOfJail();
						}
					}
					else {
						p[j].setMoney(p[j].getMoney() - 50);
						p[j].getOutOfJail();
					}
				}
				else {
					int temp = rand() % 2;
					if (temp == 0) {
						if (roll1 == roll2) p[j].getOutOfJail();
						else if (roll1 != roll2 && p[j].getJailTurn() < 3) {
							p[j].setJailTurn(p[j].getJailTurn() + 1);
							break;
						}
						else if (roll1 != roll2 && p[j].getJailTurn() == 3) {
							p[j].setMoney(p[j].getMoney() - 50);
							p[j].getOutOfJail();
						}
					}
					else {
						p[j].setMoney(p[j].getMoney() - 50);
						p[j].getOutOfJail();
					}
				}
			}
			else {
				if (roll1 == roll2) p[j].setDoubles(p[j].getDoubles() + 1);
				else if (p[j].getDoubles() > 0) p[j].setDoubles(0);
				if (p[j].getDoubles() == 3) {
					p[j].goToJail();
					p[j].setDoubles(0);
					break;
				}
			}
			p[j].move(roll1 + roll2);
		}
	}
}

bool Game::gameEnd() {
	for (int i = 0; i < NUM_OF_PLAYERS; i++) {
		if (p[i].getMoney() <= 0) return true;
	}
	return false;
}