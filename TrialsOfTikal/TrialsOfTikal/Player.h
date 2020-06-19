#pragma once
#include "Entity.h"
class Player :
	public Entity
{
public: Player();
	  //PlayerMove pMove =PlayerMove(*this);
	  void OnCollision(Entity& other);
};

