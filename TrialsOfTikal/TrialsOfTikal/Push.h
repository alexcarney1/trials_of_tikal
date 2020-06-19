#pragma once
#include "Component.h"
#include "Entity.h"
#include "Direction.h"
#include "Game.h"
class Push :
	public Component
{
public:
	Push(Entity& owner);
	void UpdateComponent();
	Entity* owner; //points at owner object //TODO: put this in component....component will need a constructor
	void TryToPush(Direction::dirs moveDir);
};

