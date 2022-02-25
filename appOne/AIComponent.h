// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include <unordered_map>
#include <string>
#include "Component.h"

class AIComponent : public Component
{
public:
	AIComponent(class Actor* owner);
	~AIComponent();
	
	void Update(float deltaTime) override;
	void ChangeState(const std::string& name);
	
	// Add a new state to the map
	void RegisterState(class AIState* state);

	class Actor* GetActor() { return mOwner; }
private:
	// Maps name of state to AIState instance
	std::unordered_map<std::string, class AIState*> mStateMap;
	// Current state we're in
	class AIState* mCurrentState;
};
