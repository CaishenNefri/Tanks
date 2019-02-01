#include "CPlayerControl.h"


void CPlayerControl::update(float mFT)
{
	if (input->IsActionTriggered(Input::Up))
		cControl->task = Task::Up;
	else if(input->IsActionTriggered(Input::Down))
		cControl->task = Task::Down;
	else if (input->IsActionTriggered(Input::Left))
		cControl->task = Task::Left;
	else if (input->IsActionTriggered(Input::Right))
		cControl->task = Task::Right;
	else
		cControl->task = Task::Idle;
	
	if (input->IsActionTriggered(Input::Shoot))
		cControl->task = Task::Shoot;
	


}