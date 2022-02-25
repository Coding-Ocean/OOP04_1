#pragma once
#include "SpriteComponent.h"
#include <vector>
class AnimSpriteComponent :
    public SpriteComponent
{
public:
    AnimSpriteComponent(class Actor* owner, int drawOrder = 100);
    void AddImage(int img);
    void SetAnimIndexRange(int start, int end, int mode);
    void Update() override;
    void Draw() override;
    void SetInterval(float interval) { mInterval = interval; }

    void SetAnimId(int id) { mAnimId = id; }
    bool GetAnimEnd() { return mAnimEnd; }
private:
    std::vector<int>mImgs;
    int mCurIdx;
    float mTimer;
    float mInterval;

    int mAnimId;
    int mPreAnimId;
    struct ANIM {
        int startIdx;
        int endIdx;
        int mode;
        ANIM(int s, int e, int m)
            :startIdx(s), endIdx(e), mode(m) {
        }
    };
    std::vector<ANIM> mAnim;

    bool mAnimEnd;
};

