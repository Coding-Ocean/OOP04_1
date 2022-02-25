#pragma once
#include <vector>
#include "GraphicComponent.h"
class AnimationComponent :
    public GraphicComponent
{
public:
    AnimationComponent(class Actor* owner,int drawOrder=100);
    void SetImage(int img);
    void SetIdx(int start, int end, int mode);

    void Update(float deltaTime) override;
    void Draw() override;

    void SetAnimId(int id) { mAnimId = id; }
    void SetMove(bool move) { mMove = move; }
    void setInterval(float interval) { mInterval = interval; }
private:
    std::vector<int> mImages;
    int mIdx;
    //アニメーション切り替え
    float mTime;
    float mInterval;
    bool mMove;
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
};

