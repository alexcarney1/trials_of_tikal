#include "Artifact.h"
#include "Game.h"
#include "ArtifactPickUp.h"
Artifact::Artifact()
{
	isWalkable = true;
	texture.loadFromFile("assets/artifact.png");
	sprite.setTexture(texture);
	//sprite.setPosition(10, 10);
	name = "Artifact";
	components.push_back(new ArtifactPickUp(*this));
}
#ssdfdfdfdf
#dddfeddfd
#HE
#dfsfsfsf
void Artifact::OnCollision(Entity& other)
{
}
