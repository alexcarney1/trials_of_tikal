#include "GoalBehavior.h"

GoalBehavior::GoalBehavior(Entity& newOwner) : owner(&newOwner), isCovered(false) {
	name = "GoalBehavior";
	//owner = &newOwner;
}

void GoalBehavior::UpdateComponent()
{
	
	if (Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos].entityInNode != NULL) {
		if (Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos].entityInNode->name.compare("Box") == 0) {
			this->isCovered = true;
		}
	}
	else {
		isCovered = false;
	}

}
