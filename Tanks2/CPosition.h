#pragma once
#include "Components.h"

class CPosition : public Component
{
public:
	sf::Vector2f position;
	sf::Vector2f lastPosition;
	sf::Vector2i mapPos;

	CPosition() = default;
	CPosition(const sf::Vector2f& mPosition) : position{ mPosition } {}

	void update(float mFT) override
	{
		mapPos.x = (int)(position.x / 16);
		mapPos.y = (int)(position.y / 16);
	}


	float x() const noexcept { return position.x; }
	float y() const noexcept { return position.y; }
};