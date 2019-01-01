#pragma once
#include "Components.h"

enum TTank {
	Player1,
	Player2,
	Enemy
};

class CTank : public Component
{
public:
	CRectangle* cRectangle;

	CTank() = default;

	void init() override
	{
		cRectangle = &entity->getComponent<CRectangle>();
	}

	void upgrade(void);
};