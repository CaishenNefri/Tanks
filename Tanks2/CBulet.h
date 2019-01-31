#pragma once
#include "Components.h"
#include <ctime>

class CBulet : public Component
{
public:
	CBulet() = default;

	unsigned int bullets;
	static const unsigned int maxBullets = 5;
	bool shooting;
	bool key;
	std::clock_t time;


	void init() override
	{
		bullets = 0;
		shooting = false;
		key = false;
		time = 0;
	}

private:	
	//void init();
	//void update() override;
};