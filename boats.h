#ifndef Boats_h
#define Boats_h

#include <iostream>
#include "Grid.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

class Boats
{
public:
	Boats();
	void inBoats();
	void drawBoats(sf::RenderWindow &window);
	void drag(sf::RenderWindow &window);
private:
	sf::Texture submarine;
	sf::Texture destroyer;
	sf::Texture cruiser;
	sf::Texture battle_ship;
	sf::Sprite b[10];
	int i = 0;
};
Boats::Boats()
{

}

void Boats::inBoats() 
{
	if (!submarine.loadFromFile("Submarine.png"))
		std::cout << "failed";
	sf::Sprite sub1(submarine);
	sub1.setPosition(840, 560);
	sub1.setScale(0.15, 0.23);
	sub1.setRotation(90);
	b[0] = sub1;

	sf::Sprite sub2(submarine);
	sub2.setPosition(870, 560);
	sub2.setScale(0.15, 0.23);
	sub2.setRotation(90);
	b[1] = sub2;

	sf::Sprite sub3(submarine);
	sub3.setPosition(900, 560);
	sub3.setScale(0.15, 0.23);
	sub3.setRotation(90);
	b[2] = sub3;

	sf::Sprite sub4(submarine);
	sub4.setPosition(930, 560);
	sub4.setScale(0.15, 0.23);
	sub4.setRotation(90);
	b[3] = sub4;

	if (!battle_ship.loadFromFile("Battle_Ship .png"))
		std::cout << "failed";
	sf::Sprite battle1(battle_ship);
	battle1.setPosition(600, 430);
	battle1.setScale(0.5, 0.5);
	battle1.setRotation(90);
	b[4] = battle1;

	if (!cruiser.loadFromFile("Cruiser.png"))
		std::cout << "failed";
	sf::Sprite cruiser1(cruiser);
	cruiser1.setPosition(610, 450);
	cruiser1.setScale(0.5, 0.9);
	//cruiser1.setRotation(90);
	b[5] = cruiser1;

	sf::Sprite cruiser2(cruiser);
	cruiser2.setPosition(660, 450);
	cruiser2.setScale(0.5, 0.9);
	//cruiser2.setRotation(90);
	b[6] = cruiser2;

	if (!destroyer.loadFromFile("destroyer.png"))
		std::cout << "failed";
	sf::Sprite destroyer1(destroyer);
	destroyer1.setPosition(720, 500);
	destroyer1.setScale(0.25, 0.18);
	//destroyer1.setRotation(90);
	b[7] = destroyer1;

	sf::Sprite destroyer2(destroyer);
	destroyer2.setPosition(750, 500);
	destroyer2.setScale(0.25, 0.18);
	//destroyer2.setRotation(90);
	b[8] = destroyer2;

	sf::Sprite destroyer3(destroyer);
	destroyer3.setPosition(780, 500);
	destroyer3.setScale(0.25, 0.18);
	//destroyer3.setRotation(90);
	b[9] = destroyer3;
	//bh.getBoats(b, window);

}

void Boats::drawBoats(sf::RenderWindow & window)
{
	for (int i = 0; i < 10; i++)
		window.draw(b[i]);
}
 void Boats::drag(sf::RenderWindow & window)
{
	 sf::Vector2i npos = sf::Mouse::getPosition(window);
	 sf::Vector2f f;
	 f.x = npos.x;
	 f.y = npos.y;
	 if (b[4].getGlobalBounds().contains(f))
	 {
		 while (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		 {
			 sf::Vector2i npos = sf::Mouse::getPosition(window);
			 cout << "in\n";
			 b[4].setPosition(npos.x, npos.y);
			 drawBoats(window);
			 window.display();
		 }
	 }
}
#endif // !Boats_h
