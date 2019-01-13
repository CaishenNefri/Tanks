#include "CTank.h"
#include "InputManager.h"

void CTank::update(float mFT)
{
}

void CTank::upgrade(void)
{
	sf::IntRect rect = cRectangle->shape.getTextureRect();
	rect.top += 16;
	cRectangle->shape.setTextureRect(rect);
}

void CTank::move(Input direction)
{
	sf::IntRect rect = cRectangle->shape.getTextureRect();
	switch (direction)
	{
	case Input::Left:
		cPhysics->velocity.x = -(cPhysics->speed);
		rect.left = 16 * 2;
		break;
	}

}

void CTank::shoot()
{
	std::cout << "SHOOT\n";
}
