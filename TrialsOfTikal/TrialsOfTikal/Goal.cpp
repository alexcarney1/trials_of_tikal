#include "Goal.h"

Goal::Goal() {
	isWalkable = true;
	hasCollision = false;
	texture.loadFromFile("assets/goal.png");
	sprite.setTexture(texture);
	//sprite.setPosition(10, 10);
}

void Goal::OnCollision(Entity& other)
{
}
