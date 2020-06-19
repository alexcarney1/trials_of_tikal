#pragma once
#include "Entity.h"
class Floor :
	public Entity
{
public: Floor();
	  void OnCollision(Entity& other);
};

