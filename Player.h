#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
	Player();
	void move(int distance);
	int getPosition();
	int getMoney();
	void getOutOfJail();
	bool inJail();
	void setDoubles(int n);
	int getDoubles();
	void goToJail();
	void setJailTurn(int n);
	int getJailTurn();
	void setMoney(int n);
	bool getOutOfJailFreeCard();
	void useJailCard();
private:
	int position, doublesCount, jailTurn, getOutOfJailFree;
	float money;
	bool jail;
};

#endif