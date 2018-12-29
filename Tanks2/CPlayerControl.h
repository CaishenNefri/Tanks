#pragma once
#include "Components.h"
#include "SFML/Graphics.hpp"
#include "InputManager.h"

class CPlayerControl : public Component
{
public:
	CPhysics* cPhysics{ nullptr };
	float speed;

	CPlayerControl() = default;
	CPlayerControl(float mSpeed) : speed{ mSpeed } {}

	void init()
	{
		cPhysics = &entity->getComponent<CPhysics>();
	}

	void update(float mFT) override
	{
		cPhysics->velocity = { 0.f, 0.f };
		auto input = InputManager::GetInstance();

		// Sprawdza czy nacisniete klawicze i odpowiednio nadaje kierunek poruszania siê	
		if (input->IsActionTriggered(Input::Up))
		{
			cPhysics->velocity.y = -speed;
		}else
		if (input->IsActionTriggered(Input::Down))
		{
			cPhysics->velocity.y = speed;
		}else
		if (input->IsActionTriggered(Input::Left))
		{
			cPhysics->velocity.x = -speed;
		}else
		if (input->IsActionTriggered(Input::Right))
		{
			cPhysics->velocity.x = speed;
		}
	}
};