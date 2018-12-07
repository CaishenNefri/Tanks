#include "pch.h"
#include "Animator.h"

Animator::Animator(int framesPerSecond, int amountFrames) :
	m_FramesPerSecond(framesPerSecond),
	m_AmountOffFrames(amountFrames - 1)
{
}

Animator::~Animator()
{
}

void Animator::Update(float elapsedSec)
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

int Animator::GetCurrentFrame() const
{
	return m_CurrentFrame;
}
