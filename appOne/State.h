#pragma once
class State
{
public:
	State(class StateComponent* OwnerCompo)
		:mOwnerCompo(OwnerCompo)
	{
	}
	// State-specific behavior
	virtual void Update() = 0;
	virtual void OnEnter() {};
	virtual void OnExit() {};
	// Getter for string name of state
	virtual const char* GetName() const = 0;
protected:
	class StateComponent* mOwnerCompo;
};
