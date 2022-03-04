#include "InputComponent.h"
#include "input.h"

InputComponent::InputComponent(Actor* owner)
	:Component(owner)
{
}

void InputComponent::ProcessInput()
{
	mJump = isTrigger(KEY_J);
	mPunch = isTrigger(KEY_K);
	mStartWalk = isPress(KEY_D);
	mStopWalk = isRelease(KEY_D);
}
