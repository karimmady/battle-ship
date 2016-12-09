#ifndef boats_h
#define boats_h
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "grid.h"
#include "menu.h"
#include <iostream>
using namespace std;

class boats
{
public:
	boats();
	~boats();
	void getboats(sf::Sprite b[10], sf::RenderWindow &window);
	void drawboats(sf::Sprite boat[10], sf::RenderWindow &window);

private:
	sf::Sprite boat[10];
	int i = 0;
};
boats::boats()
{

}
boats::~boats()
{

}
void boats::getboats(sf::Sprite b[10], sf::RenderWindow &window)
{
	sf::Vector2i pos = sf::Mouse::getPosition(window);
	sf::Vector2f f;
	f.x = pos.x;
	f.y = pos.y;
	while (sf::Mouse::isButtonPressed(sf::Mouse::Left))//&& b[4].getGlobalBounds().contains(f))
	{
		if (b[4].getGlobalBounds().contains(f))
		{
			while (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
					//grid();
					//grid g;
					sf::Vector2i npos = sf::Mouse::getPosition(window);
					cout << "in\n";
					b[4].setPosition(npos.x, npos.y);
					//window.clear();
					//g.gridu(window);
					//g.boats(window);
					window.draw(b[4]);
					window.display();
					if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
						b[4].setRotation(90);
				
			}
		}
	}
}
void boats::drawboats(sf::Sprite boat[10], sf::RenderWindow & window)
{
	for (int i = 0; i < 10; i++)
	{
		window.draw(boat[i]);
	}
}
#endif // !boats_h
