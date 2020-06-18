#pragma once
#include "Component.h"
#include "Direction.h"
#include "Entity.h"
class PlayerMove :public Component
{
public: PlayerMove(Entity& newOwner); //todo shitty def constructor....check playe rdelcations out
	  PlayerMove();
	  virtual void UpdateComponent();
	  Entity *owner; //points at owner object
	  void ReadInput();
	  void TryToMove(Direction::dirs moveDir);

};

