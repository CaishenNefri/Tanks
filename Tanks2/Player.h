#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player();
	~Player();
	void Update(float elapsedSec);
	void Draw(sf::RenderWindow* pWindow); //TODO change to virtual method

private:
	sf::RectangleShape m_Body;

};

