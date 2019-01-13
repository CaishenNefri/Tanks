#pragma once
#include "Components.h"

enum TTank {
	Player1,
	Player2,
	Enemy
};

enum Input : unsigned int;

class CTank : public Component
{
public:
	CPhysics* cPhysics{ nullptr };
	CRectangle* cRectangle{nullptr};

	CTank() = default;

	void init() override
	{
		cPhysics = &entity->getComponent<CPhysics>();
		cRectangle = &entity->getComponent<CRectangle>();
	}

	void update(float mFT) override;

	void upgrade(void);
	void move(Input direction);
	void shoot();
};