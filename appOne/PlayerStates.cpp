#include "Player.h"
#include "PlayerStates.h"
#include "graphic.h"
#include "window.h"
#include "input.h"
#include "Game.h"
#include "Actor.h"
#include "InputComponent.h"
#include "State.h"
#include "StateComponent.h"
#include "AnimSpriteComponent.h"
//-------------------------------------------------------------------
void PlayerWait::OnEnter()
{
	Player* p = dynamic_cast<Player*>(mOwnerCompo->GetActor());
	p->GetAnim()->SetAnimId(p->EWait);
}
void PlayerWait::Update()
{
	Player* p = dynamic_cast<Player*>(mOwnerCompo->GetActor());

	if (p->GetIn()->Punch())
	{
		mOwnerCompo->ChangeState("Punch");
		return;
	}
	if (p->GetIn()->StartWalk())
	{
		mOwnerCompo->ChangeState("Walk");
		return;
	}
	if (p->GetIn()->Jump())
	{
		mOwnerCompo->ChangeState("Jump");
		return;
	}
}
//-------------------------------------------------------------------
void PlayerWalk::OnEnter()
{
	Player* p = dynamic_cast<Player*>(mOwnerCompo->GetActor());
	p->GetAnim()->SetAnimId(p->EWalk);
	p->GetAnim()->SetInterval(0.0166f * 6);
}
void PlayerWalk::Update()
{
	Player* p = dynamic_cast<Player*>(mOwnerCompo->GetActor());
	if (p->GetIn()->Punch())
	{
		mOwnerCompo->ChangeState("Punch");
		return;
	}
	if (p->GetIn()->StopWalk())
	{
		mOwnerCompo->ChangeState("Wait");
		return;
	}
	if (p->GetIn()->Jump())
	{
		mOwnerCompo->ChangeState("Jump");
		return;
	}
}
//-------------------------------------------------------------------
void PlayerJump::OnEnter()
{
	Player* p = dynamic_cast<Player*>(mOwnerCompo->GetActor());
	p->GetAnim()->SetAnimId(p->EJump);
	mVel = -20*60;
	mAcc = 1.2f*60*60;
}
void PlayerJump::Update()
{
	Player* p = dynamic_cast<Player*>(mOwnerCompo->GetActor());
	VECTOR2 pos = p->GetPosition();
	pos.y += mVel * delta;
	mVel += mAcc * delta;
	//’…’n
	float landingY = height - 128 * mOwnerCompo->GetActor()->GetScale() / 2;
	if (pos.y > landingY)
	{
		pos.y = landingY;
		mOwnerCompo->ChangeState("Wait");
	}
	p->SetPosition(pos);
}
//-------------------------------------------------------------------
void PlayerPunch::OnEnter()
{
	Player* p = dynamic_cast<Player*>(mOwnerCompo->GetActor());
	p->GetAnim()->SetAnimId(p->EPunch);
	p->GetAnim()->SetInterval(0.0166f * 3);
}
void PlayerPunch::Update()
{
	Player* p = dynamic_cast<Player*>(mOwnerCompo->GetActor());
	
	if (p->GetAnim()->GetAnimEnd())
	{
		mOwnerCompo->ChangeState("Wait");
	}
}
