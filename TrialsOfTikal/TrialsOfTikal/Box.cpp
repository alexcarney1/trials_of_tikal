#include "Box.h"
#include "Push.h"
#include "LavaFiller.h"
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
}
