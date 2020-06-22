#pragma once
#include "Entity.h"
#include "BreakTheFloor.h"
class BrokenFloor :
	public Entity
{
public:
	BrokenFloor();
	void OnCollision(Entity& other);
};

