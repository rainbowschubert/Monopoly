#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>
#include <cmath>
#include "Player.h"

Player::Player() {
	position = 0, doublesCount = 0, jailTurn = 1, getOutOfJailFree = 0;
	money = 1500;
	jail = false;
}

void Player::move(int distance) {
	position += distance;
	if (position >= 40) money += 200;
	position = position % 40;
	if (position == 7 || position == 22 || position == 36) {//chance
		int card = rand() % 16;
		switch (card) {
		case 0: {
			money += 200;
			break;
		}
		case 1: {
			if (position >= 24) money += 200;
			position = 24;
			break;
		}
		case 2: {
			if (position >= 11) money += 200;
			position = 11;
			break;
		}
		case 3: {
			//Advance token to nearest Utility. If unowned, you may buy it from the Bank. If owned, throw dice and pay owner a total ten times the amount thrown.
			if (abs(position - 12) > abs(position - 28)) position = 28;
			else position = 12;
			break;
		}
		case 4: {//Advance token to the nearest Railroad and pay owner twice the rental to which he/she {he} is otherwise entitled. If Railroad is unowned, you may buy it from the Bank.
			if (position == 7) position = 5;
			else if (position == 22) position = 25;
			else position = 35;
			break;
		}
		case 5: {
			money += 50;
			break;
		}
		case 6: {
			getOutOfJailFree++;//get out of jail free
			break;
		}
		case 7: {
			position -= 3;
			position = position % 40;
			break;
		}
		case 8: {//go to jail
			goToJail();
			break;
		}
		case 9: {
			//Make general repairs on all your property–For each house pay $25–For each hotel $100
			break;
		}
		case 10: {
			money -= 15;
			break;
		}
		case 11: {
			if (position >= 5) money += 200;
			position = 5;
			break;
		}
		case 12: {
			position = 39;
			break;
		}
		case 13: {
			//You have been elected Chairman of the Board–Pay each player $50
			break;
		}
		case 14: {
			money += 150;
			break;
		}
		case 15: {
			money += 100;
			break;
		}
		}
	}
	if (position == 2 || position == 17 || position == 33) {//community chest
		int card = rand() % 17;
		switch (card) {
		case 0: {
			position = 0, money += 200;
			break;
		}
		case 1: {
			money += 200;
			break;
		}
		case 2: {
			money -= 50;
			break;
		}
		case 3: {
			money += 50;
			break;
		}
		case 4: {
			getOutOfJailFree++;//get out of jail free card
			break;
		}
		case 5: {//go directly to jail
			goToJail();
			break;
		}
		case 6: {//Grand Opera Night—Collect $50 from every player for opening night seats
			break;
		}
		case 7: {
			money += 100;
			break;
		}
		case 8: {
			money += 20;
			break;
		}
		case 9: {
			money += 10;
			break;
		}
		case 10: {
			money += 100;
			break;
		}
		case 11: {
			money -= 100;
			break;
		}
		case 12: {
			money -= 150;
			break;
		}
		case 13: {
			money -= 25;
			break;
		}
		case 14: {//You are assessed for street repairs–$40 per house–$115 per hotel
			break;
		}
		case 15: {
			money += 10;
			break;
		}
		case 16: {
			money += 100;
			break;
		}
		}
	}

	if (getPosition() == 30) goToJail();
}

int Player::getPosition() {
	return position;
}

int Player::getMoney() {
	return money;
}

void Player::getOutOfJail() {
	jail = false;
	setJailTurn(1);
}

bool Player::inJail() {
	return jail;
}

void Player::setDoubles(int n) {
	doublesCount = n;
}

int Player::getDoubles() {
	return doublesCount;
}

void Player::goToJail() {
	position = 10;
	jail = true;
}

void Player::setJailTurn(int n) {
	jailTurn = n;
}

int Player::getJailTurn() {
	return jailTurn;
}

void Player::setMoney(int n) {
	money = n;
}

bool Player::getOutOfJailFreeCard() {
	if (getOutOfJailFree > 0) return true;
	return false;
}

void Player::useJailCard() {
	getOutOfJailFree--;
	getOutOfJail();
}