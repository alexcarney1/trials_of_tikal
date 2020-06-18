#pragma once
#include "Component.h"
#include "Direction.h"
class PlayerMove :public Component
{
public: PlayerMove();
	  virtual void Update();
	  void ReadInput();
	  void TryToMove(Direction::dirs moveDir);

};

