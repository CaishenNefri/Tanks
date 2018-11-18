#include "pch.h"
#include "Tank.h"

void Tank::move(sf::Vector2f trend)
{
	sf::Vector2f pos = tank.getPosition();
	tank.setPosition(pos + trend);
}
