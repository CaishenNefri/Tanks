#include "Collision.h"
#include "Components.h"

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

bool Collision::AABB(const CRectangle & colA, const CRectangle & colB)
{
	if (colA.shape.getGlobalBounds().intersects(
		colB.shape.getGlobalBounds()
	))
		return true;
	else return false;
}
