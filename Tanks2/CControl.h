#pragma once
#include "ECS.h"
#include "Components.h"


enum class Task : std::size_t
{
	Up, Down, Left, Right, Shoot, Idle
};

class CControl : public Component
{
public:
	CPhysics* cPhysics{ nullptr };
	CRectangle* cRectangle{ nullptr };
	CAnimation* cAnimation{ nullptr };
	CBulet* cBulet{ nullptr };

	Task task;

	CControl() = default;

	void init() override
	{
		cPhysics = &entity->getComponent<CPhysics>();
		cRectangle = &entity->getComponent<CRectangle>();
		cAnimation = &entity->getComponent<CAnimation>();
		cBulet = &entity->getComponent<CBulet>();
		task = Task::Idle;
	}

	void update(float mFT) override;
};