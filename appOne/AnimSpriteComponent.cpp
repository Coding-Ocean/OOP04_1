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

void AnimSpriteComponent::SetRange(int start, int end, int mode)
{
    mRange.emplace_back(start, end, mode);
}

void AnimSpriteComponent::Update()
{
    //アニメーション切り替え時の初期化
    if (mPreAnimId != mAnimId) {
        mCurIdx = mRange[mAnimId].startIdx;
        mTimer = 0;
        mAnimEnd = false;
    }
    mPreAnimId = mAnimId;
    //画像切り替え・mCurIdxの更新
    mTimer += delta;
    if (mTimer > mInterval) {
        ++mCurIdx;
        if (mCurIdx > mRange[mAnimId].endIdx) {
            if (mRange[mAnimId].mode == 1)
            {
                mCurIdx = mRange[mAnimId].startIdx;
            }
            else
            {
                mCurIdx = mRange[mAnimId].endIdx;
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

