#include "graphic.h"
#include "input.h"
#include "Game.h"
#include "StateComponent.h"
#include "AnimSpriteComponent.h"
#include "Player.h"
#include "PlayerStates.h"

Player::Player(Game* game)
	:Actor(game)
	, mAsc(nullptr)
{
	//‰æ‘œ‚Ì‚‚³‚ÆŠg‘å—¦‚©‚ç°‚É—§‚ÂˆÊ’u‚ğŒvZ
	float texH = 128;
	float scale = 3;
	SetPosition(VECTOR2(width / 2, height - texH * scale / 2));
	SetScale(scale);

	mAsc = new AnimSpriteComponent(this, 50);
	char filename[128];
	for (int i = 0; i <= 9; i++)
	{
		sprintf_s(filename, "%s%02d.%s", "assets\\Character", i, "png");
		mAsc->AddImage(loadImage(filename));
	}
	mAsc->SetAnimIndexRange(0, 0, 0);//0 Wait
	mAsc->SetAnimIndexRange(0, 5, 1);//1 Walk
	mAsc->SetAnimIndexRange(6, 6, 0);//2 Jump
	mAsc->SetAnimIndexRange(7, 9, 0);//3 Punch

	auto sc = new StateComponent(this);
	sc->RegisterState(new PlayerWait(sc));
	sc->RegisterState(new PlayerWalk(sc));
	sc->RegisterState(new PlayerJump(sc));
	sc->RegisterState(new PlayerPunch(sc));
	sc->ChangeState("Wait");
}

void Player::ActorInput()
{
	mJump = isTrigger(KEY_J);
	mPunch = isTrigger(KEY_K);
	mStartWalk = isPress(KEY_D);
	mStopWalk = isRelease(KEY_D);
}
