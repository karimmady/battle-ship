#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "menu.h"
#include "grid.h"
#include"boats.h"
#include <iostream>
using namespace std;
int main()
{
	bool bisho = false;
	sf::RenderWindow window(sf::VideoMode(1000, 600), "Battle ship");
	menub();
	menub m;
	m.menu(1000, 600, window);
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
				m.mouse(sf::Mouse::getPosition(window), window,bisho);
			}
			/*while (bisho)
			{
				grid g;
				grid();
				boats br;
					window.clear();
					g.gridu(window);
					g.boats(window);
					g.drawboats(window);
					window.display();
			
			}*/
			/*if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)
			{
				grid g;
				grid();
				g.gridu(window);
				while (window.isOpen())
				{
					window.clear();
					g.gridu(window);
					g.boats(window);
					window.display();
				}
			}*/
		}
		window.clear();
		m.background(window);
		m.draw(window);
		window.display();
	}
	return EXIT_SUCCESS;
}
