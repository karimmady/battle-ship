#ifndef grid_h
#define grid_h

#include<iostream>
#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "boats.h"
#include "play.h"
#include "ai.h"
using namespace std;

class grid {
	friend class ai;
	friend class play;
private:
	sf::Sprite usgrid;
	sf::Texture user_grid;
	sf::RectangleShape playerVisibleGrid[10][10];
	sf::RectangleShape compVisibleGrid[10][10];
	boats playerBoats;
	play game;
public:
	void setgrid(sf::RenderWindow &window);
	void handleEvents(sf::RenderWindow &window, sf::Event event);
	void draw(sf::RenderWindow &window);
};


void grid::setgrid(sf::RenderWindow &window){
	// player Grid
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			playerVisibleGrid[i][j].setOutlineThickness(5);
			playerVisibleGrid[i][j].setOutlineColor(sf::Color::Black);
			playerVisibleGrid[i][j].setFillColor(sf::Color(32, 50, 81));
			playerVisibleGrid[i][j].setSize(sf::Vector2f(50, 50));
			playerVisibleGrid[i][j].setPosition(
				sf::Vector2f(50 + j * 50,
				50 + i * 50));
		}
	}

	// computer Grid
	int compGridStartX = 50 * (10 + 2);
	int compGridStartY = 50;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			compVisibleGrid[i][j].setOutlineThickness(5);
			compVisibleGrid[i][j].setOutlineColor(sf::Color::Black);
			compVisibleGrid[i][j].setFillColor(sf::Color(32, 50, 81));
			compVisibleGrid[i][j].setSize(sf::Vector2f(25, 25));
			compVisibleGrid[i][j].setPosition(
				sf::Vector2f(compGridStartX + j * 25,
				compGridStartX + i * 25));
		}
	}
}

void grid::handleEvents(sf::RenderWindow &window, sf::Event event) {
	playerBoats.handleEvents(window, event);
	if (playerBoats.start)
		game.run(playerBoats, *this);
}
void grid::draw(sf::RenderWindow &window){
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			window.draw(playerVisibleGrid[i][j]);
			window.draw(compVisibleGrid[i][j]);
		}
	playerBoats.drawboats(window);
}


#endif // grid_h
