#ifndef Grid_h
#define Grid_h
#include<iostream>
#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Boats.h"
#include "menu.h"

class Grid
{
private:
	const int q = 50;
	int userGrid[10][10];
	sf::Sprite usGrid;
	sf::Texture user_Grid;
	sf::RectangleShape smalla[10][10];
	Boats boats;
public:
	Grid();
	void setGrid(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
};

Grid::Grid()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			userGrid[i][j] = 0;
}

void Grid::setGrid(sf::RenderWindow &window)
{
	int x = 0, y = 0;
	for (int i = 0; i<10; i++)
		for (int j = 0; j<10; j++) {
			sf::RectangleShape small(sf::Vector2f(q, q));
			small.setOutlineThickness(5);
			small.setOutlineColor(sf::Color::Black);
			small.setFillColor(sf::Color(32, 50, 81));
			small.setPosition(x + (q), y + (q));
			smalla[i][j] = small;
			if (j == 9)
			{
				y += q;
				x = 0;
			}
			else
				x += q;
		}
}

void Grid::draw(sf::RenderWindow &window) {
	for (int i = 0; i<10; i++)
		for (int j = 0; j<10; j++)
			window.draw(smalla[i][j]);

	boats.drawBoats(window);
}

#endif // Grid_h
