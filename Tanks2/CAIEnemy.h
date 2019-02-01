#pragma once
#include "Components.h"

class CAIEnemy : public Component
{
public:
	CAIEnemy() = default;
	CAIEnemy(int** mGrid) : grid(mGrid) {};
	CPosition* cPosition{ nullptr };
	CControl* cControl{ nullptr };

	bool isSee = false;

	void init() override
	{
		cPosition = &entity->getComponent<CPosition>();
		cControl = &entity->getComponent<CControl>();
		destPos.x *= 16;
		destPos.y *= 16; 
	}

	void update(float mFT) override;
	sf::Vector2i destPos{ 0, 2 };
private:
	int** grid;
	const int mapX = 13;
	const int mapY = 13;
	//sf::Vector2i destPos{ 0, 2 };
	std::size_t direction;
	//Task task;
};