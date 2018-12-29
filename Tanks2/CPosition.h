#pragma once
#include "Components.h"
#include "SFML/Graphics.hpp"

class CPosition : public Component
{
public:
	sf::Vector2f position;

	CPosition() = default;
	CPosition(const sf::Vector2f& mPosition) : position{ mPosition } {}

	float x() const noexcept { return position.x; }
	float y() const noexcept { return position.y; }
};