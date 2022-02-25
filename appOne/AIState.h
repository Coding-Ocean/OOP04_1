// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once

class AIState
{
public:
	AIState(class AIComponent* OwnerCompo)
		:mOwnerCompo(OwnerCompo)
	{ }
	// State-specific behavior
	virtual void Update(float deltaTime) = 0;
	virtual void OnEnter() {};
	virtual void OnExit() {};
	// Getter for string name of state
	virtual const char* GetName() const = 0;
protected:
	class AIComponent* mOwnerCompo;
};
