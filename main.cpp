#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <ctime>
#include "Menu.h"
#include "Grid.h"
#include "Boats.h"
using namespace std;

int main() {
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(1000, 600), "Battle ship");

	Menu m;
	m.setMenu(1000, 600, window);

	Grid g;
	g.setGrid(window);
	Boats b;
	b.inBoats();

	bool bisho = false;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				window.close();
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				m.mouse(sf::Mouse::getPosition(window), window, bisho);
			}
		}
		window.clear();
		//m.background(window);
		if (!bisho)
		{
			m.background(window);
			m.draw(window);
		}
		else {
			g.draw(window);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				b.drag(window);
			}
			

		}

		window.display();
	}
	return EXIT_SUCCESS;
}
