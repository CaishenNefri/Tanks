// Tanks2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include <SFML/Graphics.hpp>

	
int main()
{
	sf::RenderWindow window;
	window.create(sf::VideoMode(800, 600), "Tanks!");
	window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(false);

	sf::Texture mushroomTexture;
	mushroomTexture.loadFromFile("tank.png");
	sf::Sprite mushroom(mushroomTexture);
	sf::Vector2f scale = mushroom.getScale();
	mushroom.setScale(scale.x / 10, scale.y / 10);

	sf::Vector2u size = mushroomTexture.getSize();
	mushroom.setOrigin(size.x / 10, size.y / 10);
	sf::Vector2f increment(0.4f, 0.4f);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		sf::Vector2f position = mushroom.getPosition();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			sf::Vector2f move(1,0);
			mushroom.setPosition(position + move);
			std::cout << "Przycisk Prawa strzalka nacisniety!" << std::endl;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			sf::Vector2f move(0, 1);
			mushroom.setPosition(position - move);
			std::cout << "Przycisk Prawa strzalka nacisniety!" << std::endl;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			sf::Vector2f move(0, 1);
			mushroom.setPosition(position + move);
			std::cout << "Przycisk Prawa strzalka nacisniety!" << std::endl;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			sf::Vector2f move(1, 0);
			mushroom.setPosition(position - move);
			std::cout << "Przycisk Prawa strzalka nacisniety!" << std::endl;
		}

		
		window.clear(sf::Color(16, 16, 16, 255)); // Dark gray.
		window.draw(mushroom); // Drawing our sprite.
		window.display();
	}


	return 0;
}
