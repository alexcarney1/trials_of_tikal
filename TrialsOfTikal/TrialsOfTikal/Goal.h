#pragma once
#include "Entity.h"
class Goal :
	public Entity
{
public: Goal();
	  void OnCollision(Entity& other);
};

