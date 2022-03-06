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
    //�A�j���[�V�����؂�ւ����̏�����
    if (mPreAnimId != mAnimId) {
        mCurIdx = mAnims[mAnimId].startIdx;
        mTimer = 0;
        mAnimEnd = false;
    }
    mPreAnimId = mAnimId;
    //�摜�؂�ւ��EmCurIdx�̍X�V
    mTimer += delta;
    if (mTimer > mInterval) {
        ++mCurIdx;
        if (mCurIdx > mAnims[mAnimId].endIdx) {
            if (mAnims[mAnimId].loopMode == 1)
            {
                //���[�v���邽�߂ɃC���f�b�N�X���ŏ��ɖ߂�
                mCurIdx = mAnims[mAnimId].startIdx;
            }
            else
            {
                //���[�v�����Ȃ��̂ōŌ�̃C���f�b�N�X�̂܂܂ɂ���
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

