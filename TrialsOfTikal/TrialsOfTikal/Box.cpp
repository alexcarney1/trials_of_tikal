#include "Box.h"
#include "Push.h"
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
}
