#pragma once
#include "Component.h"
#include "Entity.h"
class LavaToFloor :
	public Component
{
public:
	LavaToFloor(Entity& newOwner);
	void UpdateComponent();
	void FillInLava();
	Entity* owner; //points at owner object //TODO: put this in component....component will need a constructor
};

