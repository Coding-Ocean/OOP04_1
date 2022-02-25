#pragma once
#include "State.h"
//-----------------------------------------------------------------------------
class PlayerWait : public State
{
public:
	PlayerWait(class StateComponent* OwnerCompo) :State(OwnerCompo) { }
	const char* GetName() const override { return "Wait"; }
	void OnEnter() override;
	void Update() override;
};
//-----------------------------------------------------------------------------
class PlayerWalk : public State
{
public:
	PlayerWalk(class StateComponent* OwnerCompo) :State(OwnerCompo) { }
	const char* GetName() const override { return "Walk"; }
	void OnEnter() override;
	void Update() override;
};
//-----------------------------------------------------------------------------
class PlayerJump : public State
{
public:
	PlayerJump(class StateComponent* OwnerCompo) :State(OwnerCompo) { }
	const char* GetName() const override { return "Jump"; }
	void OnEnter() override;
	void Update() override;
private:
	float mVel;
	float mAcc;
};
//-----------------------------------------------------------------------------
class PlayerPunch : public State
{
public:
	PlayerPunch(class StateComponent* OwnerCompo) :State(OwnerCompo) { }
	const char* GetName() const override { return "Punch"; }
	void OnEnter() override;
	void Update() override;
};
