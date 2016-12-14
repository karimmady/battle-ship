#ifndef Menu_hpp
#define Menu_hpp

#include<iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

class Menu
{
public:
	Menu();
	void setMenu(float width, float height, sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
	void background(sf::RenderWindow &window);
	void mouse(sf::Vector2i, sf::RenderWindow &window, bool &bisho);
private:
	sf::Font font;
	sf::Text txt[4];
	sf::FloatRect b[4];
	sf::Texture back;
	sf::Vector2f point;
};

Menu::Menu()
{
	if (!font.loadFromFile("STENCIL.TTF"))
	{
		cout << "Error\n";
	}
}

void Menu::setMenu(float width, float height, sf::RenderWindow &window) {
	txt[0].setFont(font);
	txt[0].setColor(sf::Color::White);
	txt[0].setString("Play");
	txt[0].setPosition(sf::Vector2f(width / 16, height / 1.3));

	txt[1].setFont(font);
	txt[1].setColor(sf::Color::White);
	txt[1].setString("Highscore");
	txt[1].setPosition(sf::Vector2f(width / 3.5, height / 1.3));

	txt[2].setFont(font);
	txt[2].setColor(sf::Color::White);
	txt[2].setString("Instructions");
	txt[2].setPosition(sf::Vector2f(width / 1.7, height / 1.3));

	txt[3].setFont(font);
	txt[3].setColor(sf::Color::White);
	txt[3].setString("Exit");
	txt[3].setPosition(sf::Vector2f(width / 1.103, height / 1.3));

	b[0] = txt[0].getGlobalBounds();
	b[1] = txt[1].getGlobalBounds();
	b[2] = txt[2].getGlobalBounds();
	b[3] = txt[3].getGlobalBounds();
	point = sf::Vector2f(b[3].left + 1.f, b[3].top + 1.f);
}


void Menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < 4; i++)
	{
		window.draw(txt[i]);
	}
}

void Menu::background(sf::RenderWindow &window)
{
	if (!back.loadFromFile("Battle_ship_Background.jpg"))
		cout << "failed";
	sf::Sprite sprite(back);
	sprite.setPosition(0, 0);
	sprite.setScale(0.85, 0.6);
	window.draw(sprite);
}
void Menu::mouse(sf::Vector2i pos, sf::RenderWindow &window, bool &bisho)
{
	sf::Vector2f f;
	f.x = pos.x;
	f.y = pos.y;
	if (txt[0].getGlobalBounds().contains(f))
	{
		bisho = true;
	}

	if (txt[1].getGlobalBounds().contains(f))
	{
	}
	if (txt[2].getGlobalBounds().contains(f))
	{
		//cout << "hi mazen\n" << endl;
	}
	if (txt[3].getGlobalBounds().contains(f))
	{
		exit(0);
	}
}
#endif /* Menu_hpp */
