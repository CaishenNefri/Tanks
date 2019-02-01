#include "CAIEnemy.h"

void CAIEnemy::update(float mFT)
{

	/*auto actPos = cPosition->mapPos;
	if(actPos )*/

	/*int percentage = rand() % 100;
	if (percentage <= 80)
	{
		auto& task = cControl->task;
		int rand = std::rand() % 3;
		switch (rand)
		{
		case 0:
			task = Task::Up;
			break;
		case 1:
			task = Task::Left;
			break;
		case 2:
			task = Task::Right;
			break;
		}

	}
	else
		cControl->task = Task::Down;*/

	

	sf::Vector2i actPos = cPosition->mapPos;
	if (destPos.x > actPos.x)
		cControl->task  = Task::Right;
	else if (destPos.x < actPos.x)
		cControl->task  = Task::Left;
	else if (destPos.y > actPos.y)
		cControl->task  = Task::Down;
	else if (destPos.y < actPos.y)
		cControl->task = Task::Up;
}
