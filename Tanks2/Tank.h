#pragma once

#include <SFML/Graphics.hpp>

class Tank {
public:
	Tank();
	~Tank();
	void move(sf::Vector2f trend);
private:
	sf::Sprite tank;
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

};