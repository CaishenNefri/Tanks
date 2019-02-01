#pragma once
#include "Components.h"

class CPlayer: public Component
{
public:
	CPlayer(int mLives=3)
	{
		lives = mLives;
	}

	int lives;
};