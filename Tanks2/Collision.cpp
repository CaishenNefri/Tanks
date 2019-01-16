#include "Collision.h"
#include "Components.h"
#include "SFML/Graphics.hpp"

sf::FloatRect Collision::windowRect = sf::FloatRect{ 0.f, 0.f, 832.f, 664.f };

void Collision::colissionPlayer(Entity & a, Entity & b)
{
	if (a.getComponent<CRectangle>().shape.getGlobalBounds().intersects(
		b.getComponent<CRectangle>().shape.getGlobalBounds()
	))
	{
		a.getComponent<CTank>().upgrade();
		b.destroy();
	}
}

//A with walls and window borders
bool Collision::AABB(const CRectangle & colA, const CRectangle & colB)
{
	if (colA.shape.getGlobalBounds().intersects(
		colB.shape.getGlobalBounds()) ||
		//Collision with window bounds
		(colA.cPosition->position.y <= 0.f ||
			(colA.cPosition->position.y + colA.shape.getSize().y) >= windowRect.height) ||
		(colA.cPosition->position.x <= 0.f ||
			(colA.cPosition->position.x + colA.shape.getSize().x) >= windowRect.width))
		return true;
	else return false;
}
