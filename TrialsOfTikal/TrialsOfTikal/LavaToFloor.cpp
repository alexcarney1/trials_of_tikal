#include "LavaToFloor.h"
#include "Game.h"
LavaToFloor::LavaToFloor(Entity& newOwner) : owner(&newOwner){
	name = "LavaToFloor";

	//owner = &newOwner;
}

void LavaToFloor::UpdateComponent()
{
}

void LavaToFloor::FillInLava()
{
	owner->hasCollision = false;
	owner->texture.loadFromFile("assets/lavaFilled.png");
	owner->sprite.setTexture(owner->texture);
	owner->sprite.setPosition(owner->GridYPos*32,owner->GridXPos*32);
	owner->isWalkable = true;
}
