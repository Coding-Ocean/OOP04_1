#include "StateComponent.h"
#include "State.h"
#include "Actor.h"

StateComponent::StateComponent(class Actor* owner)
	:Component(owner)
	, mCurrentState(nullptr)
{
}

StateComponent::~StateComponent()
{
	for (auto& stateMap : mStateMap)
	{
		delete stateMap.second;
	}
}

void StateComponent::Update()
{
	if (mCurrentState)
	{
		mCurrentState->Update();
	}
}

void StateComponent::ChangeState(const std::string& name)
{
	// First exit the current state
	if (mCurrentState)
	{
		mCurrentState->OnExit();
	}

	// Try to find the new state from the map
	auto iter = mStateMap.find(name);
	if (iter != mStateMap.end())
	{
		mCurrentState = iter->second;
		// We're entering the new state
		mCurrentState->OnEnter();
	}
	else
	{
		//SDL_Log("Could not find State %s in state map", name.c_str());
		mCurrentState = nullptr;
	}
}

void StateComponent::RegisterState(State* state)
{
	mStateMap.emplace(state->GetName(), state);
}
