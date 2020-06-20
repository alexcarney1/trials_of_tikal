#pragma once
#include "Component.h"
#include "Direction.h"
#include "Entity.h"
#include "Game.h"
#include <string>
class GoalBehavior :
	public Component
{
public:
	GoalBehavior(Entity& newOwner);
	void UpdateComponent();
	bool isCovered;
	Entity* owner; //points at owner object //TODO: put this in component....component will need a constructor
};

