#pragma once
#include "Components.h"
#include "CTank.h"



class CPlayerControl : public Component
{
public:
	CPhysics* cPhysics{ nullptr };
	CRectangle* cRectangle{ nullptr };
	CAnimation* cAnimation{ nullptr };
	//CTank* cTank{ nullptr };

	CPlayerControl() = default;

	void init()
	{
		cPhysics = &entity->getComponent<CPhysics>();
		cRectangle = &entity->getComponent<CRectangle>();
		cAnimation = &entity->getComponent<CAnimation>();
		//cTank = &entity->getComponent<CTank>();
	}

	void update(float mFT) override;
};