#pragma once
#include "Components.h"
#include <ctime>

class CBulet : public Component
{
public:
	CBulet() = default;


	unsigned int bullets = 0;
	static const unsigned int maxBullets = 5;
	bool shooting = false;
	bool key = false;
	std::clock_t time = 0;

private:	
	//void init();
	//void update() override;
};