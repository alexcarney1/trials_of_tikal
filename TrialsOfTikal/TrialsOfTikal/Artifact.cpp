#include "Artifact.h"
#include "Game.h"
Artifact::Artifact()
{
	isWalkable = true;
	texture.loadFromFile("assets/artifact.png");
	sprite.setTexture(texture);
	//sprite.setPosition(10, 10);
	name = "Artifact";
}

void Artifact::OnCollision(Entity& other)
{
}
