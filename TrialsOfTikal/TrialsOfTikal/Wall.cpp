#include "Wall.h"

Wall::Wall() {
	isWalkable = false;
	hasCollision = true;
	texture.loadFromFile("assets/wall.png");
	sprite.setTexture(texture);
	//sprite.setPosition(10, 10);
}

void Wall::OnCollision(Entity& other)
{
}
