#include "Game.h"
#include <iostream>

using namespace std;

int main() {
	int results[40];
	for (int j = 0; j < 40; j++) results[j] = 0;
	for (int i = 0; i < 10000000; i++) {
		Game g;
		g.play(results);
	}
	for (int i = 0; i < 40; i++) cout << results[i] << endl;
}