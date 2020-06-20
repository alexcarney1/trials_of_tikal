#include "Lava.h"
#include "LavaFiller.h"
Lava::Lava()
{
	isWalkable = false;
	hasCollision = true;
	texture.loadFromFile("assets/lava.png");
	sprite.setTexture(texture);
	//sprite.setPosition(10, 10);
	name = "Lava";
	components.push_back(new LavaFiller(*this));
}

void Lava::OnCollision(Entity& other)
{
}
