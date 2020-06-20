#pragma once
#include "Entity.h"
class Monkey :
	public Entity
{
public:
	Monkey();
	void OnCollision(Entity& other);
};

