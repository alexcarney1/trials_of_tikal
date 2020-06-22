#pragma once
#include "Component.h"
#include "Entity.h"
class BreakTheFloor :
	public Component
{
public:
	BreakTheFloor(Entity& newOwner);
	void UpdateComponent();
	bool filled = false;
	void UpdateBrokenStatus(Entity &other);
	Entity* owner; //points at owner object //TODO: put this in component....component will need a constructor
	int brokenStatus = 1;
};

