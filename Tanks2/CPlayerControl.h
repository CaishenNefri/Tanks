#pragma once
#include "ECS.h"
#include "Components.h"
#include "InputManager.h"

class CControl;

class CPlayerControl : public Component
{
public:
	CControl* cControl{ nullptr };
	InputManager* input{ nullptr };

	

	CPlayerControl() = default;

	void init() override
	{
		cControl = &entity->getComponent<CControl>();
		input = InputManager::GetInstance();

	}

	void update(float mFT) override;
};