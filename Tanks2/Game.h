#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	~Game();
	void run();
	void buildMap();

private:
	void processEvents();
	void update();
	void render();
	
	sf::RenderWindow window;
	sf::Texture texture;
	sf::Sprite mushroom;
	int windowHeight = 416;
	int windowWidth = 416;
};