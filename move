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
				//grid g;
				//grid();
				sf::Vector2i npos = sf::Mouse::getPosition(window);
				cout << "in\n";
				b[4].setPosition(npos.x, npos.y);
				window.clear();
				g.gridu(window);
				g.boats(window);
				window.draw(b[4]);
				window.display();
	

			}
		}
