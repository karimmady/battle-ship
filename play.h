#ifndef PLAY_H
#define PLAY_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <ctime>
#include "grid.h"
#include "boats.h"
#include "ai.h"

using namespace std;

class play{
	friend class ai;
	friend class grid;
public:
	void run(boats &playerBoats, grid &playerCompGrid);
	bool userhit(sf::RectangleShape compVisibleGrid[10][10], int compArray[10][10]);
private:
	int turn = 0;
	ai comp;
};


void play::run(boats &playerBoats, grid &playerCompGrid){
	if (turn % 2 == 0){ // player Turn
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			if (!userhit(playerCompGrid.compVisibleGrid, comp.compArray)) 
				turn++;
	}
	else {
		if (comp.arthit(!playerCompGrid.playerVisibleGrid, playerBoats))
			turn++;
	}
}
bool play::userhit(sf::RectangleShape compVisibleGrid[10][10], int compArray[10][10]){
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		sf::Vector2i pos = sf::Mouse::getPosition();
		sf::Vector2f f;
		f.x = pos.x; f.y = pos.y;
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++) {
				if (compVisibleGrid[i][j].getGlobalBounds().contains(f)) {
					if (compArray[i][j] == 1) {		// has a ship
						compArray[i][j] = 3;	// destroyed
						compVisibleGrid[i][j].setFillColor(sf::Color::Red);
						return true;
					}
					else if (compArray[i][j] == 0) {	// doesn't have a ship
						compArray[i][j] == 2;	// mark it as a hit
						compVisibleGrid[i][j].setFillColor(sf::Color::Green);
					}
				}
			}
	}
	return false;
}
#endif PLAY_H
