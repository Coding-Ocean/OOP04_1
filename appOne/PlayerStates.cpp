#include "PlayerStates.h"
#include "graphic.h"
#include "input.h"
#include "Game.h"
#include "Actor.h"
#include "State.h"
#include "StateComponent.h"
#include "AnimSpriteComponent.h"
#include "Player.h"
//-------------------------------------------------------------------
void PlayerWait::OnEnter()
{
	Player* p = dynamic_cast<Player*>(mOwnerCompo->GetActor());
	p->GetAnim()->SetAnimId(0);
}
void PlayerWait::Update()
{
	Player* p = dynamic_cast<Player*>(mOwnerCompo->GetActor());

	if (p->Punch())
	{
		mOwnerCompo->ChangeState("Punch");
		return;
	}
	if (p->StartWalk())
	{
		mOwnerCompo->ChangeState("Walk");
		return;
	}
	if (p->Jump())
	{
		mOwnerCompo->ChangeState("Jump");
		return;
	}
}
//-------------------------------------------------------------------
void PlayerWalk::OnEnter()
{
	Player* p = dynamic_cast<Player*>(mOwnerCompo->GetActor());
	p->GetAnim()->SetAnimId(1);
	p->GetAnim()->SetInterval(0.0166f * 6);
}
void PlayerWalk::Update()
{
	Player* p = dynamic_cast<Player*>(mOwnerCompo->GetActor());
	if (p->Punch())
	{
		mOwnerCompo->ChangeState("Punch");
		return;
	}
	if (p->StopWalk())
	{
		mOwnerCompo->ChangeState("Wait");
		return;
	}
	if (p->Jump())
	{
		mOwnerCompo->ChangeState("Jump");
		return;
	}
}
//-------------------------------------------------------------------
void PlayerJump::OnEnter()
{
	Player* p = dynamic_cast<Player*>(mOwnerCompo->GetActor());
	p->GetAnim()->SetAnimId(2);
	p->GetAnim()->SetInterval(0.0166f * 28);
	mVel = -20;
	mAcc = 1.0f;
}
void PlayerJump::Update()
{
	Player* p = dynamic_cast<Player*>(mOwnerCompo->GetActor());
	VECTOR2 pos = p->GetPosition();
	pos.y += mVel;
	mVel += mAcc;
	//’…’n
	if (pos.y > height - 128 * mOwnerCompo->GetActor()->GetScale() / 2)
	{
		pos.y = height - 128 * mOwnerCompo->GetActor()->GetScale() / 2;
		mOwnerCompo->ChangeState("Wait");
	}
	p->SetPosition(pos);
}
//-------------------------------------------------------------------
void PlayerPunch::OnEnter()
{
	Player* p = dynamic_cast<Player*>(mOwnerCompo->GetActor());
	p->GetAnim()->SetAnimId(3);
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
