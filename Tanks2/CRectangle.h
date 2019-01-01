#pragma once
#include "Components.h"
#include "SFML/Graphics.hpp"
#include <iostream>

class Game;


class CRectangle : public Component
{
public:
	Game* game{ nullptr };
	CPosition* cPosition{ nullptr };
	CPhysics* cPhysics{ nullptr };

	sf::RectangleShape shape;
	sf::Vector2f size;
	std::string tag;

	CRectangle(Game* mGame, const sf::Vector2f& mSize)
		: game{ mGame }, size{ mSize }
	{}

	CRectangle(Game* mGame, const sf::Vector2f& mSize, const std::string mTag)
		: game{ mGame }, size{ mSize }, tag{ mTag }
	{}

	void init() override
	{
		cPosition = &entity->getComponent<CPosition>();
		cPhysics = &entity->getComponent<CPhysics>();

		shape.setSize(size);
	}
	void update(float mFT) override
	{
		shape.setPosition(cPosition->position);
	}
	void draw() override;
};