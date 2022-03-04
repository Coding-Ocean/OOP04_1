#pragma once
#include "Component.h"
class InputComponent :
    public Component
{
public:
    InputComponent(class Actor* owner);
    void ProcessInput() override;
    int Jump() { return mJump; }
    int Punch() { return mPunch; }
    int StartWalk() { return mStartWalk; }
    int StopWalk() { return mStopWalk; }
private:
    int mJump;
    int mPunch;
    int mStartWalk;
    int mStopWalk;
};

