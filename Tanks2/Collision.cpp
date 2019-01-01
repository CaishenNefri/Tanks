#include "Collision.h"
#include "Components.h"

void Collision::colissionPlayer(Entity & a, Entity & b)
{
	if (a.getComponent<CRectangle>().shape.getGlobalBounds().intersects(
		b.getComponent<CRectangle>().shape.getGlobalBounds()
	))
	{
		std::cout << "Intersect\n";
		a.getComponent<CTank>().upgrade();
		b.destroy();
	}
	else std::cout << "NOT\n";
}
