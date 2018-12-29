#pragma once
#include "Components.h"
#include "SFML/Graphics.hpp"

class Game;


class CRectangle : public Component
{
public:
	Game* game{ nullptr };
	CPosition* cPosition{ nullptr };
	sf::RectangleShape shape;
	sf::Vector2f size;

	CRectangle(Game* mGame, const sf::Vector2f& mSize)
		: game{ mGame }, size{ mSize }
	{}

	void init() override
	{
		cPosition = &entity->getComponent<CPosition>();

		shape.setSize(size);
	}
	void update(float mFT) override
	{
		shape.setPosition(cPosition->position);
	}
	void draw() override;
};