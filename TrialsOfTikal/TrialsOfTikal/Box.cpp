#include "Box.h"

Box::Box() {
	isWalkable = false;
	hasCollision = true;
	texture.loadFromFile("assets/box.png");
	sprite.setTexture(texture);
	//sprite.setPosition(10, 10);
}

void Box::OnCollision(Entity& other)
{
}
