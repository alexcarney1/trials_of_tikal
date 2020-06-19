#pragma once
#include "Component.h"
#include "Direction.h"
#include "Entity.h"
class PlayerMove :public Component
{
public: PlayerMove(Entity& newOwner); 
	  void UpdateComponent();
	  Entity *owner; //points at owner object //TODO: put this in component....component will need a constructor
	  void ReadInput();
	  void TryToMove(Direction::dirs moveDir);

};

