#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <ctime>
#include "Menu.h"
#include "grid.h"
#include "boats.h"
using namespace std;

int main() {
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(1000, 600), "Battle ship");

	Menu m;
	m.setMenu(1000, 600, window);

	grid g;
	g.setgrid(window);
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
			g.handleEvents(window, event);
			g.draw(window);
		}

		window.display();
	}
	return EXIT_SUCCESS;
}
