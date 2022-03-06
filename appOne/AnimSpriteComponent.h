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
    //画像切り替え系
    void AddImage(int img);
    void SetInterval(float interval) { mInterval = interval; }
    //アニメーション切り替え系
    void SetAnim(int startIdx, int endIdx, int loopMode);
    void SetAnimId(int id) { mAnimId = id; }
    bool GetAnimEnd() { return mAnimEnd; }
private:
    //画像切り替え系
    std::vector<int>mImgs;
    int mCurIdx;
    float mTimer;
    float mInterval;
    //アニメーション切り替え系
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
    //アニメーション終了フラッグ
    bool mAnimEnd;
};

