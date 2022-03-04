#include "graphic.h"
#include "input.h"
#include "Game.h"
#include "InputComponent.h"
#include "StateComponent.h"
#include "AnimSpriteComponent.h"
#include "Player.h"
#include "PlayerStates.h"

Player::Player(Game* game)
	:Actor(game)
{
	//画像の高さと拡大率から床に立つ位置を計算
	float texH = 128;
	float scale = 5;
	SetPosition(VECTOR2(width / 2, height - texH * scale / 2));
	SetScale(scale);

	//入力
	mIn = new InputComponent(this);

	//アニメーション画像読み込み
	mAnim = new AnimSpriteComponent(this, 50);
	char filename[128];
	for (int i = 0; i <= 9; i++)
	{
		sprintf_s(filename, "%s%02d.%s", "assets\\Character", i, "png");
		mAnim->AddImage(loadImage(filename));
	}
	//アニメーションごとの(開始インデックス、終了インデックス、ループモード)
	mAnim->SetRange(0, 0, 0);//Wait
	mAnim->SetRange(0, 5, 1);//Walk Loop
	mAnim->SetRange(6, 6, 0);//Jump
	mAnim->SetRange(7, 9, 0);//Punch

	//Actor状態切り替えコンポーネント
	mState = new StateComponent(this);
	mState->RegisterState(new PlayerWait(mState));
	mState->RegisterState(new PlayerWalk(mState));
	mState->RegisterState(new PlayerJump(mState));
	mState->RegisterState(new PlayerPunch(mState));
	mState->ChangeState("Wait");
}
