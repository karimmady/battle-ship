#ifndef boats_h
#define boats_h
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "menu.h"
#include "grid.h"
#include <iostream>
using namespace std;

class boats
{
public:
	boats();
	~boats();
	void getboats(sf::Sprite b[10], sf::RenderWindow &window);

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
	//sf::Vector2i position = sf::Mouse::getPosition(window);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		for (int i = 0; i < 10; i++)
		{
			sf::Vector2i pos = sf::Mouse::getPosition(window);
			sf::Vector2f f;
			f.x = pos.x;
			f.y = pos.y;
			if (b[i].getGlobalBounds().contains(f))
			{
				b[i].setPosition(pos.x, pos.y);
				window.draw(b[i]);
			}
		}


	}

	/*{
		for (int i = 0; i < 10; i++)
		{
			if ((position.x - b[i].getPosition().x) < b[i].getPosition().x && (position.y - b[i].getPosition().y) < b[i].getPosition().y)
			{
				b[i].setPosition(position.x, position.y);
				window.draw(b[i]);
			}
		}
	}*/
}
#endif // !boats_h
