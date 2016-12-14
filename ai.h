#ifndef ai_h
#define ai_h

#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <ctime>
#include "play.h"
#include "grid.h"
#include "boats.h"

using namespace std;

class ai {
	friend class play;
	friend class grid;
private:
	int compArray[10][10];
public:
	ai();
	bool arthit(sf::RectangleShape playerVisibleGrid[10][10], boats &playerBoats);
};

ai::ai(){
	for (int i = 0; i<10; i++)
		for (int j = 0; j<10; j++)
			compArray[i][j] = 0;
}

bool ai::arthit(sf::RectangleShape playerVisibleGrid[10][10], boats &playerBoats) {
	int x, y;
	do {
		// keep generating to get place that
		// hasn't been hit before
		x = rand() % 10;
		y = rand() % 10;
	} while (playerBoats.usergrid[x][y] != 1 && playerBoats.usergrid[x][y] != 0);

	if (playerBoats.usergrid[x][y] == 1){	// ship
		playerVisibleGrid[x][y].setFillColor(sf::Color::Red);
		playerBoats.usergrid[x][y] == 3;	// destroyed
		return true; // hit
	}
	else if (playerBoats.usergrid[x][y] == 0) { // no ship
		playerVisibleGrid[x][y].setFillColor(sf::Color::Green);
		playerBoats.usergrid[x][y] == 2;	// hit
		return false; // didn't hit
	}
}

#endif ai_h
