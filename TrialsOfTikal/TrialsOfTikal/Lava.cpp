#include "Lava.h"

Lava::Lava()
{
	isWalkable = false;
	hasCollision = true;
	texture.loadFromFile("assets/lava.png");
	sprite.setTexture(texture);
	//sprite.setPosition(10, 10);
	name = "Lava";
}

void Lava::OnCollision(Entity& other)
{
}
