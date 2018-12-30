#pragma once
#include "Components.h"
#include "SFML/Graphics.hpp"
#include "InputManager.h"


class CPlayerControl : public Component
{
public:
	CPhysics* cPhysics{ nullptr };
	CRectangle* cRectangle{ nullptr };
	CAnimation* cAnimation{ nullptr };
	float speed;

	CPlayerControl() = default;
	CPlayerControl(float mSpeed) : speed{ mSpeed } {}

	void init()
	{
		cPhysics = &entity->getComponent<CPhysics>();
		cRectangle = &entity->getComponent<CRectangle>();
		cAnimation = &entity->getComponent<CAnimation>();
	}

	void update(float mFT) override
	{
		cPhysics->velocity = { 0.f, 0.f };
		sf::IntRect rect = cRectangle->shape.getTextureRect();
		auto input = InputManager::GetInstance();

		// Sprawdza czy nacisniete klawicze i odpowiednio nadaje kierunek poruszania siê	
		if (input->IsActionTriggered(Input::Up))
		{
			cPhysics->velocity.y = -speed;
			rect.left = 0;
			
		}else
		if (input->IsActionTriggered(Input::Down))
		{
			cPhysics->velocity.y = speed;
			rect.left = 16*4;
		}else
		if (input->IsActionTriggered(Input::Left))
		{
			cPhysics->velocity.x = -speed;
			rect.left = 16 * 2;
		}else
		if (input->IsActionTriggered(Input::Right))
		{
			cPhysics->velocity.x = speed;
			rect.left = 16 * 6;
		}

		if (cPhysics->velocity.x != 0 || cPhysics->velocity.y !=0)
		{
			int frame = cAnimation->m_CurrentFrame;
			rect.left += 16 * frame;
			cRectangle->shape.setTextureRect(rect);
		}
		
	}
};