#include "AnimSpriteComponent.h"
#include "window.h"

AnimSpriteComponent::AnimSpriteComponent(Actor* owner, int drawOrder)
	:SpriteComponent(owner, drawOrder)
	, mCurIdx(0)
	, mTimer(0.0f)
	, mInterval(0.0f)
    , mAnimId(0)
{
}

void AnimSpriteComponent::AddImage(int img)
{
	mImgs.emplace_back(img);
}

void AnimSpriteComponent::SetAnimIndexRange(int start, int end, int mode)
{
    mAnim.emplace_back(start, end, mode);
}

void AnimSpriteComponent::Update()
{
    if (mPreAnimId != mAnimId) {
        mCurIdx = mAnim[mAnimId].startIdx;
        mTimer = 0;
        mAnimEnd = false;
    }
    mPreAnimId = mAnimId;
    mTimer += delta;
    if (mTimer > mInterval) {
        ++mCurIdx;
        if (mCurIdx > mAnim[mAnimId].endIdx) {
            if (mAnim[mAnimId].mode == 1)
            {
                mCurIdx = mAnim[mAnimId].startIdx;
            }
            else
            {
                mCurIdx = mAnim[mAnimId].endIdx;
                mAnimEnd = true;
            }
        }
        mTimer -= mInterval;
    }
}

void AnimSpriteComponent::Draw()
{
    SpriteComponent::SetImage(mImgs[mCurIdx]);
	SpriteComponent::Draw();
}

