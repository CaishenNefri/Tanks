#include "SystemTank.h"
#include "Components.h"
#include "InputManager.h"



SystemTank::SystemTank()
{
}


SystemTank::~SystemTank()
{
}

void SystemTank::update(Entity & entity)
{
	switch (entity.getComponent<CTank>().tag)
	{
	case TTank::Player1:
		updatePlayer(entity);
		break;
	case TTank::Enemy:
		updateEnemy(entity);
		break;
	}
}

void SystemTank::updatePlayer(Entity & entity)
{
	CPhysics* cPhysics{ nullptr };
	CRectangle* cRectangle{ nullptr };
	CAnimation* cAnimation{ nullptr };
	CBulet* cBulet{ nullptr };

	cPhysics = *entity.getComponent<CPhysics>();
	cRectangle = *entity.getComponent<CRectangle>();
	cAnimation = entity.getComponent<CAnimation>();
	cBulet = entity.getComponent<CBulet>();


	auto input = InputManager::GetInstance();

	// Sprawdza czy nacisniete klawicze i odpowiednio nadaje kierunek poruszania siê	
	if (input->IsActionTriggered(Input::Up))
	{
		cPhysics->velocity.y = -speed;
		rect.left = 0;
	}
	else
		if (input->IsActionTriggered(Input::Down))
		{
			cPhysics->velocity.y = speed;
			rect.left = 16 * 4;
		}
		else
			if (input->IsActionTriggered(Input::Left))
			{
				cPhysics->velocity.x = -speed;
				rect.left = 16 * 2;
			}
			else
				if (input->IsActionTriggered(Input::Right))
				{
					cPhysics->velocity.x = speed;
					rect.left = 16 * 6;
				}

	//shooting
	if (input->IsActionTriggered(Input::Shoot))
	{
		if (!cBulet->key)
		{
			cBulet->key = true;
			cBulet->shooting = true;
		}

	}
}

void SystemTank::updateEnemy(Entity & entity)
{
}

