#pragma once
#include "SpriteComponent.h"
#include <vector>
class AnimSpriteComponent :
    public SpriteComponent
{
public:
    AnimSpriteComponent(class Actor* owner, int drawOrder = 100);
    void AddImage(int img);
    void SetRange(int start, int end, int mode);
    void Update() override;
    void Draw() override;
    void SetInterval(float interval) { mInterval = interval; }

    void SetAnimId(int id) { mAnimId = id; }
    bool GetAnimEnd() { return mAnimEnd; }
private:
    //画像切り替え
    std::vector<int>mImgs;
    int mCurIdx;
    float mTimer;
    float mInterval;
    //アニメーション切り替え
    int mAnimId;
    int mPreAnimId;
    struct Range 
    {
        int startIdx;
        int endIdx;
        int mode;
        Range(int s, int e, int m)
            :startIdx(s), endIdx(e), mode(m) {}
    };
    std::vector<Range> mRange;

    bool mAnimEnd;
};

