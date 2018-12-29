#pragma once
#include "Components.h"
#include "SFML/Graphics.hpp"

class CPhysics : public Component
{
public:
	CPosition* cPosition{ nullptr };
	sf::Vector2f velocity, size;

	CPhysics() = default;
	CPhysics(const sf::Vector2f& mSize) : size{ mSize } {}


	void init() override
	{
		cPosition = &entity->getComponent<CPosition>();
	}

	void update(float mFT) override
	{
		cPosition->position += velocity * mFT;

		// test colision
	}


	float x() const noexcept { return cPosition->x(); }
	float y() const noexcept { return cPosition->y(); }
};