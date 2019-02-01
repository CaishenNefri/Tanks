#pragma once
#include "Components.h"

class CAIEnemy : public Component
{
public:
	CAIEnemy() = default;
	CAIEnemy(int** mGrid, int mType) : grid(mGrid), type(mType) {};
	CPosition* cPosition{ nullptr };
	CControl* cControl{ nullptr };

	bool isSee = false;
	int type;

	void init() override
	{
		cPosition = &entity->getComponent<CPosition>();
		cControl = &entity->getComponent<CControl>();

		switch (type)
		{
		case 0: destPos = sf::Vector2i{ 6, 12 }; break;
		case 1: break;
		default: destPos = sf::Vector2i{ 0,0 }; break;
		}
	}

	void update(float mFT) override;
	sf::Vector2i destPos;
private:
	int** grid;
	const int mapX = 13;
	const int mapY = 13;
	std::size_t direction;
};