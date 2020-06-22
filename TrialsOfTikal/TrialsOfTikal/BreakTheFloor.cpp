#include "BreakTheFloor.h"
#include "Game.h"

BreakTheFloor::BreakTheFloor(Entity& newOwner) : owner(&newOwner)
{
	name = "BreakTheFloor";

}

void BreakTheFloor::UpdateComponent()
{
}

void BreakTheFloor::UpdateBrokenStatus(Entity& other)
{
	if (!filled) {
		//TODO: maybe name compare
		if (other.GetComponent("PlayerMove") != NULL) {
			brokenStatus += 1;

		}
		if (other.name.compare("Box") == 0) {
			printf("box on");
			//brokenStatus += 2;
			other.taggedToDie = true;
			owner->texture.loadFromFile("assets/lavaFilled.png");
			filled = true;
			owner->killOnContact = false;

		}

		if (!filled) {
			if (brokenStatus == 2) {
				owner->texture.loadFromFile("assets/crackedFloor2.png");
			}
			else if (brokenStatus == 3) {
				owner->texture.loadFromFile("assets/brokenFloor.png");
				owner->killOnContact = true;
			}
		}

	}

}
