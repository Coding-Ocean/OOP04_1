#pragma once
#include "Actor.h"
class Player :
    public Actor
{
public:
    Player(class Game* gmae);
    class InputComponent* GetIn() { return mIn; }
    class AnimSpriteComponent* GetAnim() { return mAnim; }
    enum AnimId{EWait,EWalk,EJump,EPunch,ENumId};
private:
    class InputComponent* mIn;
    class AnimSpriteComponent* mAnim;
    class StateComponent* mState;
};

