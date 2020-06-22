#include "BrokenFloor.h"

BrokenFloor::BrokenFloor()
{
	isWalkable = true;
	killOnContact = false;
	texture.loadFromFile("assets/crackedFloor1.png");
	sprite.setTexture(texture);
	name = "BrokenFloor";
	components.push_back(new BreakTheFloor(*this));
}

void BrokenFloor::OnCollision(Entity& other)
{
}

