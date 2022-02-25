#include "graphic.h"
#include "input.h"
#include "Game.h"
#include "Actor.h"
#include "AnimationComponent.h"

AnimationComponent::AnimationComponent(Actor* owner, int order)
    :GraphicComponent(owner, order)
    ,mTime(0)
    ,mIdx(0)
{
    mAnimId = 0;
    mPreAnimId = 0;
    mInterval = 0.1f;
    mMove = false;
}

void AnimationComponent::SetImage(int img)
{
    mImages.emplace_back(img);
}

void AnimationComponent::SetIdx(int start, int end, int mode)
{
    mAnim.emplace_back(start, end, mode);
}

void AnimationComponent::Update(float deltaTime)
{
    if (mMove) {
        if (mPreAnimId != mAnimId) {
            mIdx = mAnim[mAnimId].startIdx;
        }
        mPreAnimId = mAnimId;
        mTime += deltaTime;
        if (mTime > mInterval) {
            ++mIdx;
            if (mIdx > mAnim[mAnimId].endIdx) {
                if (mAnim[mAnimId].mode == 1)
                    mIdx = mAnim[mAnimId].startIdx;
                else
                    mIdx = mAnim[mAnimId].endIdx;
            }
            mTime -= mInterval;
        }
    }
    else {
        mIdx = mAnim[mAnimId].startIdx;
    }
}

void AnimationComponent::Draw()
{
    rectMode(CENTER);
    float px = mOwner->GetPosition().x;
    float py = mOwner->GetPosition().y;
    float r = mOwner->GetRotation();
    float s = mOwner->GetScale();
    image(mImages[mIdx], px, py, r, s);
}

