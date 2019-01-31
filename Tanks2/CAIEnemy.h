#pragma once
#include "ECS.h"
#include "Components.h"
#include <cstdlib>



class CAIEnemy : public Component
{
public:
	CPhysics* cPhysics{ nullptr };
	CRectangle* cRectangle{ nullptr };
	CAnimation* cAnimation{ nullptr };
	//CBulet* cBulet{ nullptr };

	CAIEnemy() = default;
	CAIEnemy(sf::RenderWindow* mWindow) : window(mWindow) {}

	void init() override
	{
		cPhysics = &entity->getComponent<CPhysics>();
		cRectangle = &entity->getComponent<CRectangle>();
		cAnimation = &entity->getComponent<CAnimation>();
		//cBulet = &entity->getComponent<CBulet>();
	}

	void update(float mFT) override
	{
		cPhysics->velocity = { 0.f, 0.f };
		float speed = cPhysics->speed;
		sf::IntRect rect = cRectangle->shape.getTextureRect();
		//auto input = InputManager::GetInstance();

		int direction = std::rand() % 5;

		switch (direction)
		{
		case 0:
			cPhysics->velocity.y = -speed;
			rect.left = 0;
			break;
		case 1:
			cPhysics->velocity.y = speed;
			rect.left = 16 * 4;
			break;
		case 2:
			cPhysics->velocity.x = -speed;
			rect.left = 16 * 2;
			break;
		case 3:
			cPhysics->velocity.x = speed;
			rect.left = 16 * 6;
			break;
		/*case 4:
			if (!cBulet->key)
			{
				cBulet->key = true;
				cBulet->shooting = true;
			}
			break;*/
		}

		if (cPhysics->velocity.x != 0 || cPhysics->velocity.y != 0)
		{
			int frame = cAnimation->m_CurrentFrame;
			rect.left += (16 * frame);
			cRectangle->shape.setTextureRect(rect);
		}
	}

private:
	sf::RenderWindow* window;
	bool isXPressed = false;
};