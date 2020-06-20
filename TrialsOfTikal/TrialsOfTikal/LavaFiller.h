#pragma once
#include "Component.h"
#include "Entity.h"
class LavaFiller :
	public Component
{
public:
	LavaFiller(Entity& newOwner);
	void UpdateComponent();
	void FillLava();
	bool isFilled = false;
	Entity* owner; //points at owner object //TODO: put this in component....component will need a constructor
};

