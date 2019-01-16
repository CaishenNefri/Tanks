#pragma once
#include "Components.h"

class CPhysics : public Component
{
public:
	CPosition* cPosition{ nullptr };
	sf::Vector2f velocity, size;
	float speed;

	CPhysics() = default;
	CPhysics(const sf::Vector2f& mSize) : size{ mSize } {}
	CPhysics(const sf::Vector2f& mSize, float mSpeed) : size{ mSize }, speed{ mSpeed } {}


	void init() override
	{
		cPosition = &entity->getComponent<CPosition>();
	}

	void update(float mFT) override
	{
		cPosition->position += velocity * mFT;
	}


	float x() const noexcept { return cPosition->x(); }
	float y() const noexcept { return cPosition->y(); }
};