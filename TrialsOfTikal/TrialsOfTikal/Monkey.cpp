#include "Monkey.h"
#include "PlayerMove.h"
#include "Push.h"
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
	if (other.name.compare("Artifact") == 0) {
		printf("hit artifact");
		Game::activeLevel->numArtifactsCollected += 1;
		other.taggedToDie = true;
		//Game::activeLevel->layer2[other.GridXPos][other.GridYPos].entityInNode = NULL;
	}
}
