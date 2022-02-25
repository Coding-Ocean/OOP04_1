#pragma once
#include "Actor.h"
class Player :
    public Actor
{
public:
    Player(class Game* gmae);
    void ActorInput() override;
    class AnimSpriteComponent* GetAnim() { return mAsc; }
    int Jump() { return mJump; }
    int Punch() { return mPunch; }
    int StartWalk() { return mStartWalk; }
    int StopWalk() { return mStopWalk; }
private:
    class AnimSpriteComponent* mAsc;
    int mJump;
    int mPunch;
    int mStartWalk;
    int mStopWalk;
};

