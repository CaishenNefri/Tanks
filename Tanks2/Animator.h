#pragma once
class Animator
{
public:
	Animator(int framesPerSecond, int amountFrames);
	~Animator();
	void Update(float elapsedSec);
	int GetCurrentFrame() const;

private:
	int m_CurrentFrame = 0;
	int m_FramesPerSecond = 0;
	int m_AmountOffFrames = 0;
	float m_Timer = 0.f;
};

