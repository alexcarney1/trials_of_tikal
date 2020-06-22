#include "GoalBehavior.h"
#include <iostream>
GoalBehavior::GoalBehavior(Entity& newOwner) : owner(&newOwner), isCovered(false) {
	name = "GoalBehavior";
	//owner = &newOwner;
}

void GoalBehavior::UpdateComponent()
{

	if (Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos].entityInNode != NULL) {
		
		if (Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos].entityInNode->name.compare("Box") == 0) {
			//std::cout << Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos].entityInNode->name << std::endl;
			this->isCovered = true;
			return;
		}
	}
	
	this->isCovered = false;

	


}
