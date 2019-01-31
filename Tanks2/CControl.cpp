#include "CControl.h"

void CControl::update(float mFT)
{
	cPhysics->velocity = { 0.f, 0.f };
	float speed = cPhysics->speed;
	sf::IntRect rect = cRectangle->shape.getTextureRect();

	switch (task)
	{
	case Task::Up:
		cPhysics->velocity.y = -speed;
		rect.left = 0;
		break;
	case Task::Down:
		cPhysics->velocity.y = speed;
		rect.left = 16 * 4;
		break;
	case Task::Left:
		cPhysics->velocity.x = -speed;
		rect.left = 16 * 2;
		break;
	case Task::Right:
		cPhysics->velocity.x = speed;
		rect.left = 16 * 6;
		break;
	case Task::Shoot:
		if (!(cBulet->key))
		{
			cBulet->key = true;
			cBulet->shooting = true;
		}
		break;
	}

	task = Task::Idle;

	if (cPhysics->velocity.x != 0 || cPhysics->velocity.y != 0)
	{
		int frame = cAnimation->m_CurrentFrame;
		rect.left += (16 * frame);
		cRectangle->shape.setTextureRect(rect);
	}
}
