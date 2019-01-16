#include "ShootingManager.h"
#include "CBulet.h"
#include <iostream>



ShootingManager::ShootingManager()
{
}


ShootingManager::~ShootingManager()
{
}

bool ShootingManager::shooting(CBulet& cBulet)
{
	if (isShooting(cBulet) &&
		(cBulet.bullets < cBulet.maxBullets))
	{
		std::cout << "STRELAJ!!XD!!!\n";
		return true;
	}

	if ((std::clock() - cBulet.time) > delayTime)
		cBulet.key = false;

	return false;
}

bool ShootingManager::isShooting(CBulet& cBulet)
{
	if (cBulet.shooting)
	{
		cBulet.time = clock();
		cBulet.shooting = false;
		return true;
	}
	return false;
}

Entity & ShootingManager::createBulet(Game * game, Manager & manager, Entity & tank, std::size_t group)
{
	sf::Vector2f sizeBullet{ 16.f, 16.f };
	sf::Vector2f positionBullet;
	sf::Vector2f sizeTank = tank.getComponent<CPhysics>().size;
	sf::Vector2f positionTank = tank.getComponent<CPosition>().position;
	
	int rectLeft = tank.getComponent<CRectangle>().shape.getTextureRect().left;
	rectLeft = rectLeft / 16;
	sf::Vector2f velocity;
	
	
	auto& entity(manager.addEntity());
	entity.addComponent<CPosition>();
	entity.addComponent<CPhysics>(sizeBullet, 500);
	entity.addComponent<CRectangle>(game);
	entity.addGroup(group);

	float speedBullet = entity.getComponent<CPhysics>().speed;
	if (rectLeft == 0 || rectLeft == 1) // turn up
	{
		positionBullet = { positionTank.x + sizeTank.x / 2, positionTank.y };
		velocity.y = -speedBullet;
	} else if (rectLeft == 2 || rectLeft == 3) // turn left
	{
		positionBullet = { positionTank.x, positionTank.y + sizeTank.y / 2 };
		velocity.x = -speedBullet;
	}
	else if (rectLeft == 4 || rectLeft == 5) // turn down
	{
		positionBullet = { positionTank.x + sizeTank.x / 2, positionTank.y + sizeTank.y };
		velocity.y = speedBullet;
	}
	else if (rectLeft == 6 || rectLeft == 7) // turn right
	{
		positionBullet = { positionTank.x + sizeTank.x, positionTank.y + sizeTank.y / 2 };
		velocity.x = speedBullet;
	}

	sf::RectangleShape shape{ sizeBullet };
	shape.setFillColor(sf::Color::Red);


	entity.getComponent<CPosition>().position = positionBullet;
	entity.getComponent<CPhysics>().velocity = velocity;
	entity.getComponent<CRectangle>().shape = shape;
	return entity;
}
