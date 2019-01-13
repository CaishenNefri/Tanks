#pragma once
#include "Components.h"

class CAnimation : public Component
{
public:
	int m_CurrentFrame = 0;
	int m_FramesPerSecond = 0;
	int m_AmountOffFrames = 0;
	float m_Timer = 0.f;

	CAnimation() = default;

	CAnimation(int mFramePerSecond, int mAmountFrames) :
		m_FramesPerSecond(mFramePerSecond),
		m_AmountOffFrames(mAmountFrames - 1)
	{}


	void update(float elapsedSec) override
	{
		m_Timer += elapsedSec;

		if (m_Timer >= (1.0f / m_FramesPerSecond))
		{
			m_Timer = 0.0f;

			++m_CurrentFrame;
			if (m_CurrentFrame > m_AmountOffFrames)
			{
				m_CurrentFrame = 0;
			}
		}
	}
};