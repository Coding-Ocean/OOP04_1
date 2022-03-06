#pragma once
#include "SpriteComponent.h"
#include <vector>
class AnimSpriteComponent :
    public SpriteComponent
{
public:
    AnimSpriteComponent(class Actor* owner, int drawOrder = 100);
    void Update() override;
    void Draw() override;
    //�摜�؂�ւ��n
    void AddImage(int img);
    void SetInterval(float interval) { mInterval = interval; }
    //�A�j���[�V�����؂�ւ��n
    void SetAnim(int startIdx, int endIdx, int loopMode);
    void SetAnimId(int id) { mAnimId = id; }
    bool GetAnimEnd() { return mAnimEnd; }
private:
    //�摜�؂�ւ��n
    std::vector<int>mImgs;
    int mCurIdx;
    float mTimer;
    float mInterval;
    //�A�j���[�V�����؂�ւ��n
    int mAnimId;
    int mPreAnimId;
    struct Anim
    {
        int startIdx;
        int endIdx;
        int loopMode;
        Anim(int s, int e, int m)
            :startIdx(s), endIdx(e), loopMode(m) {}
    };
    std::vector<Anim> mAnims;
    //�A�j���[�V�����I���t���b�O
    bool mAnimEnd;
};

