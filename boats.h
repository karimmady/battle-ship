#ifndef boats_h
#define boats_h

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "grid.h"
#include "play.h"
#include "ai.h"

using namespace std;

class boats {
	friend class grid;
	friend class play;
	friend class ai;
public:
	boats();
	void drawboats(sf::RenderWindow &window);
	void handleEvents(sf::RenderWindow & window, sf::Event & event);
	void setShips(int index, int num, int ShipSize,
		sf::Texture & texture, int startX, int startY, int TileSize);
private:
	sf::Texture submarine;
	sf::Texture destroyer;
	sf::Texture cruiser;
	sf::Texture battle_ship;
	sf::Sprite b[10];
	sf::Font font;
	sf::Text text;
	bool moved[10];
	int sizes[10];
	int usergrid[10][10];
	int recx = 0;
	int recy = 0;
	bool start = false;
};

void boats::setShips(int index, int num, int ShipSize,
	sf::Texture & texture, int startX, int startY, int TileSize)
{

	sf::Vector2u textureSize = texture.getSize();
	sf::Vector2f scale;
	scale.x = float(TileSize) / textureSize.x;

	scale.y = float(TileSize*ShipSize) / textureSize.y;
	for (int i = index; i < index + num; i++)
	{
		b[i].setTexture(texture);
		b[i].setPosition(startX + (i - index) * 60, startY);
		b[i].setScale(scale);
	}
}
boats::boats(){
	for (int i = 0; i < 10; i++) 
		for (int j = 0; j < 10; j++)
			usergrid[i][j] = 0;

	for (int i = 0; i < 10; i++)
		moved[i] = false;

	if (!submarine.loadFromFile("Submarine.png"))
		std::cout << "failed";

	if (!destroyer.loadFromFile("destroyer.png"))
		std::cout << "failed";

	if (!cruiser.loadFromFile("Cruiser.png"))
		std::cout << "failed";

	if (!battle_ship.loadFromFile("Battle_Ship .png"))
		std::cout << "failed";


	setShips(0, 4, 1, submarine, 740, 400, 45);
	setShips(4, 3, 2, destroyer, 740, 460, 45);
	setShips(7, 2, 3, cruiser, 620, 400, 45);
	setShips(9, 1, 4, battle_ship, 560, 400, 45);

	if (!font.loadFromFile("STENCIL.TTF"))
	{
		cout << "Error\n";
	}
	text.setFont(font);
	text.setColor(sf::Color::White);
	text.setString("start");
	text.setPosition(sf::Vector2f(680, 50));


	int h = 1;
	for (int i = 0; i < 10; i++){
		if (i == 4)
			h++;
		else if (i == 7)
			h++;
		else if (i == 9)
			h++;
		sizes[i] = h;
	}
}
void boats::drawboats(sf::RenderWindow & window)
{
	window.draw(text);
	for (int i = 0; i < 10; i++)
		window.draw(b[i]);
}

void boats::handleEvents(sf::RenderWindow & window, sf::Event &event)
{
	static bool  dragging = false;
	static bool  rotate = false;
	static sf::Sprite * movingShip;
	static sf::Vector2i orignalLocation;
	static sf::Vector2i oldLocation;
	static int currMovingIndex = -1;

	switch (event.type) {
	case sf::Event::MouseButtonPressed:
	{
		if (!dragging && event.mouseButton.button == sf::Mouse::Left) {
			oldLocation = sf::Mouse::getPosition(window);
			sf::Vector2f f;
			f.x = oldLocation.x;			f.y = oldLocation.y;
			for (int i = 0; i < 10; i++)
				if (b[i].getGlobalBounds().contains(f) && !moved[i]){
					currMovingIndex = i;
					movingShip = &b[i];
					dragging = true;
					orignalLocation.x = movingShip->getPosition().x;
					orignalLocation.y = movingShip->getPosition().y;
					if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
						rotate = true;
					break;
				}
		}
	}
	break;

	case sf::Event::MouseMoved:{
		if (dragging) {
			sf::Vector2i curr = sf::Mouse::getPosition(window);
			sf::Vector2f offset;
			offset.x = curr.x - oldLocation.x;
			offset.y = curr.y - oldLocation.y;
			movingShip->move(offset);
			oldLocation.x = curr.x;
			oldLocation.y = curr.y;
		}
	}
	break;

	case sf::Event::MouseButtonReleased:
	{
		if (dragging) {
			bool validlocation = true;
			sf::FloatRect myBounds = movingShip->getGlobalBounds();
			myBounds.top -= 50; myBounds.left -= 50;
			myBounds.width += 100; myBounds.height += 100;
			sf::Vector2f currPos = movingShip->getPosition();
			if (!(currPos.x > 50 && currPos.y > 50 && currPos.x < 550 && currPos.y + sizes[currMovingIndex]*50 < 550))
				validlocation = false;
			
			for (int i = 0; i < 10 && validlocation; i++){
				if (&b[i] != movingShip){
					sf::FloatRect currBounds = b[i].getGlobalBounds();
					if (currBounds.intersects(myBounds))
						validlocation = false;
				}
			}

			if(!validlocation)
				movingShip->setPosition(float(orignalLocation.x), float(orignalLocation.y));

			else {
				int i = (currPos.y - 50) / 50;
				int j = (currPos.x - 50) / 50;
				moved[currMovingIndex] = true;
				movingShip->setPosition(float(50 + 50 * j), (float) 50 + 50 * i);
				switch (sizes[currMovingIndex]){
					case 4:
						usergrid[i + 3][j] = 1;
					case 3:
						usergrid[i + 2][j] = 1;
					case 2:
						usergrid[i + 1][j] = 1;
					case 1:
						usergrid[i][j] = 1;
				}
			}
			dragging = false;
			movingShip = NULL;
		}
	}
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		sf::Vector2i pos = sf::Mouse::getPosition(window);
		sf::Vector2f f;
		f.x = pos.x;
		f.y = pos.y;
		if (text.getGlobalBounds().contains(f)){
			start = true;
			for (int i = 0; i < 10; i++)
				if (moved[i] != 1)
					start = false;
		}
	}
}
#endif // !boats_h
