#pragma once
#include "ECS.h"
#include "Components.h"



class CPlayerControl : public Component
{
public:
	CPhysics* cPhysics{ nullptr };
	CRectangle* cRectangle{ nullptr };
	CAnimation* cAnimation{ nullptr };
	CBulet* cBulet{ nullptr };

	CPlayerControl() = default;
	CPlayerControl(sf::RenderWindow* mWindow) : window(mWindow) {}

	void init() override
	{
		cPhysics = &entity->getComponent<CPhysics>();
		cRectangle = &entity->getComponent<CRectangle>();
		cAnimation = &entity->getComponent<CAnimation>();
		cBulet = &entity->getComponent<CBulet>();
	}

	void update(float mFT) override;

private:
	sf::RenderWindow* window;
	bool isXPressed = false;
};