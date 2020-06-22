#include "Box.h"
#include "Push.h"
#include "LavaFiller.h"
#include "BreakTheFloor.h"
Box::Box() {
	isWalkable = false;
	name = "Box";
	hasCollision = true;
	texture.loadFromFile("assets/box.png");
	sprite.setTexture(texture);
	//sprite.setPosition(10, 10);
	components.push_back(new Push(*this));
}

void Box::OnCollision(Entity& other)
{
	if (other.GetComponent("LavaFiller")) {
		
		LavaFiller* lavaFiller = dynamic_cast<LavaFiller*>(other.GetComponent("LavaFiller"));
		lavaFiller->FillLava();
	}
	if (other.GetComponent("BreakTheFloor")) {
		printf("box collided");
		BreakTheFloor* btf = dynamic_cast<BreakTheFloor*>(Game::activeLevel->layer1[other.GridXPos][other.GridYPos].entityInNode->GetComponent("BreakTheFloor"));
		btf->UpdateBrokenStatus(*this);
	}

}
