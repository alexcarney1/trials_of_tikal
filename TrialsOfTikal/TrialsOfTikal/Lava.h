#pragma once
#include "Entity.h"
class Lava :
	public Entity
{
public:
	Lava();
	void OnCollision(Entity& other);
};

