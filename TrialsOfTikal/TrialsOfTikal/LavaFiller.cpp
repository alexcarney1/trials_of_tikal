#include "LavaFiller.h"
#include "Game.h"
#include <string>
LavaFiller::LavaFiller(Entity& newOwner) : owner(&newOwner)
{
	name = "LavaFiller";
}
void LavaFiller::UpdateComponent()
{
	//TODO: ghetto way of deleting a box...called after box is done with its move component...in theory
	if (Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos].entityInNode != NULL && !isFilled) {
		isFilled = true;
		owner->killOnContact = false;
		if (Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos].entityInNode->name.compare("Box") == 0) {
			delete Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos].entityInNode; //delete box
			Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos].entityInNode = NULL;
		}
	}

}
	

void LavaFiller::FillLava()
{

	
	//update lava to make it walkable, update sprite
	//Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos].entityInNode = NULL;
	owner->isWalkable = true;
	owner->hasCollision = false;
	//TODO: create a function to change sprites in entity maybe
	owner->texture.loadFromFile("assets/lavaFilled.png");
	owner->sprite.setTexture(owner->texture);
}
