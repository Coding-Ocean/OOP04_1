#pragma once
#include "State.h"
//------------------------------------------------------
class PlayerWait : public State
{
public:
	PlayerWait(class StateComponent* OwnerCompo)
		:State(OwnerCompo)
	{ }

	void OnEnter() override;
	void Update() override;

	const char* GetName() const override
	{
		return "Wait";
	}
};
//------------------------------------------------------
class PlayerWalk : public State
{
public:
	PlayerWalk(class StateComponent* OwnerCompo)
		:State(OwnerCompo)
	{ }

	// Override with behaviors for this state
	void OnEnter() override;
	void Update() override;

	const char* GetName() const override
	{
		return "Walk";
	}
};
//------------------------------------------------------
class PlayerJump : public State
{
public:
	PlayerJump(class StateComponent* OwnerCompo)
		:State(OwnerCompo)
	{ }

	void OnEnter() override;
	void Update() override;

	const char* GetName() const override
	{
		return "Jump";
	}
private:
	float mVel;
	float mAcc;
};
//------------------------------------------------------
class PlayerPunch : public State
{
public:
	PlayerPunch(class StateComponent* OwnerCompo)
		:State(OwnerCompo)
	{ }

	void OnEnter() override;
	void Update() override;

	const char* GetName() const override
	{
		return "Punch";
	}
};
