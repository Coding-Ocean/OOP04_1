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

void AnimSpriteComponent::SetAnim(int start, int end, int loopMode)
{
    mAnims.emplace_back(start, end, loopMode);
}

void AnimSpriteComponent::Update()
{
    //アニメーション切り替え時の初期化
    if (mPreAnimId != mAnimId) {
        mCurIdx = mAnims[mAnimId].startIdx;
        mTimer = 0;
        mAnimEnd = false;
    }
    mPreAnimId = mAnimId;
    //画像切り替え・mCurIdxの更新
    mTimer += delta;
    if (mTimer > mInterval) {
        ++mCurIdx;
        if (mCurIdx > mAnims[mAnimId].endIdx) {
            if (mAnims[mAnimId].loopMode == 1)
            {
                //ループするためにインデックスを最初に戻す
                mCurIdx = mAnims[mAnimId].startIdx;
            }
            else
            {
                //ループさせないので最後のインデックスのままにする
                mCurIdx = mAnims[mAnimId].endIdx;
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

