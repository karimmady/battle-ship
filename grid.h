#ifndef grid_h
#define grid_h
#include<iostream>
#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include"boats.h"
#include"menu.h"
class grid
{
private:
	const int q = 50;
	int usergrid[10][10];
	sf::Sprite usgrid;
	sf::Texture user_grid;
	sf::Texture submarine;
	sf::Texture destroyer;
	sf::Texture cruiser;
	sf::Texture battle_ship;
	sf::RectangleShape smalla[10][10];
	boats bh;
	sf::Sprite b[10];
public:
	grid();
	void gridu(sf::RenderWindow &window);
	~grid();
	void drawboats(sf::RenderWindow &window);
	void boats(sf::RenderWindow &window);

};
grid::grid()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			usergrid[i][j] = 0;

}

void grid::gridu(sf::RenderWindow &window)
{
	srand(time(NULL));
	int x = 0;
	int y = 0;

	for (int i = 0; i<10; i++)
		for (int j = 0; j<10; j++)
		{
		    sf::RectangleShape small(sf::Vector2f(q, q));
			small.setOutlineThickness(5);
			small.setOutlineColor(sf::Color::Black);
			small.setFillColor(sf::Color(32, 50, 81));
			small.setPosition(x + (q), y + (q));
			smalla[i][j]=small;
			window.draw(smalla[i][j]);
			if (j == 9)
			{
				y += q;
				x = 0;
			}
			else
				x += q;
		}
	sf::RectangleShape small1(sf::Vector2f(25, 25));
	small1.setOutlineThickness(5);
	small1.setOutlineColor(sf::Color::Black);
	small1.setFillColor(sf::Color(32, 50, 81));
	srand(time(NULL));
	x = 0;
	y = 0;

	for (int i = 0; i<10; i++)
		for (int j = 0; j<10; j++)
		{

			//usergrid[i][j] = &small;
			small1.setPosition(x+700, y+100);
			window.draw(small1);
			if (j == 9)
			{
				y += 25;
				x = 0;
			}
			else
				x += 25;
		}

}
grid::~grid()
{
}
 void grid::drawboats(sf::RenderWindow &window)
{
	 for (int i = 0; i < 10; i++)
	 {
		 window.draw(b[i]);
	 }
	 bh.getboats(b, window);
}
 void grid::boats(sf::RenderWindow &window)
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
		 //bh.getboats(b, window);
 }
#endif grid_h
