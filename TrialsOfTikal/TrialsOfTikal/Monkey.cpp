#include "Monkey.h"
#include "PlayerMove.h"
#include "Push.h"
#include "ArtifactPickUp.h"
Monkey::Monkey()
{
	//playerMove = PlayerMove();
	isWalkable = false;
	texture.loadFromFile("assets/monkey.png");
	sprite.setTexture(texture);
	//sprite.setPosition(10, 10);
	name = "Monkey";
	components.push_back(new PlayerMove(*this));
	components.push_back(new Push(*this));
}

void Monkey::OnCollision(Entity& other)
{
	//cleanup this index
	if (Game::activeLevel->layer2[other.GridXPos][other.GridYPos].entityInNode != NULL) {
		if (Game::activeLevel->layer2[other.GridXPos][other.GridYPos].entityInNode->GetComponent("ArtifactPickUp")) {
			ArtifactPickUp* arti = dynamic_cast<ArtifactPickUp*>(Game::activeLevel->layer2[other.GridXPos][other.GridYPos].entityInNode->GetComponent("ArtifactPickUp"));
			arti->PickUp();
		}
	}
	if (other.killOnContact) {
		//Game::ResetLevel();
		taggedToDie = true;
		return;
	}
}
