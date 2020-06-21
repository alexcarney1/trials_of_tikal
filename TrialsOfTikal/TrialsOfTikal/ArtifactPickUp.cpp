#include "ArtifactPickUp.h"
#include "Game.h"
ArtifactPickUp::ArtifactPickUp(Entity& newOwner) : owner(&newOwner)
{
	name = "ArtifactPickUp";
}

void ArtifactPickUp::UpdateComponent()
{

}

void ArtifactPickUp::PickUp()
{
	Game::activeLevel->numArtifactsCollected += 1;
	//other.taggedToDie = true;
	//delete &other;
	//delete owner;
	Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos].entityInNode = NULL;
}
