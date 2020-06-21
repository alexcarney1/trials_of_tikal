#pragma once
#include "Entity.h"
class Artifact :
	public Entity
{
public:
	Artifact();
	void OnCollision(Entity& other);
};

