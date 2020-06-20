#include "Push.h"

Push::Push(Entity& newOwner) : owner(&newOwner)
{
	name = "Push";
}

void Push::UpdateComponent()
{
}

//not checking all layers here. oops.
void Push::TryToPush(Direction::dirs moveDir)
{
	if (moveDir == Direction::NORTH) {
		if (Game::activeLevel->layer2[owner->GridXPos - 1][owner->GridYPos].entityInNode != NULL
			&& Game::activeLevel->layer2[owner->GridXPos - 1][owner->GridYPos].entityInNode->hasCollision) {
			owner->OnCollision(*(Game::activeLevel->layer2[owner->GridXPos - 1][owner->GridYPos].entityInNode));
			owner->OnCollision(*(Game::activeLevel->layer1[owner->GridXPos - 1][owner->GridYPos].entityInNode));
			if (Game::activeLevel->layer2[owner->GridXPos - 1][owner->GridYPos].entityInNode->GetComponent("Push")) {
				Push* pushComp = dynamic_cast<Push*>(Game::activeLevel->layer2[owner->GridXPos - 1][owner->GridYPos].entityInNode->GetComponent("Push"));
				pushComp->TryToPush(moveDir);
			}
		}

		if (Game::activeLevel->layer2[owner->GridXPos - 1][owner->GridYPos].entityInNode == NULL && Game::activeLevel->layer1[owner->GridXPos - 1][owner->GridYPos].entityInNode->isWalkable) {
			//printf("Move successful!");
			Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos].entityInNode = NULL; //reset old pos to NULL TODO: ABSTRACT THIS OUT
			Game::activeLevel->layer2[owner->GridXPos - 1][owner->GridYPos].entityInNode = owner;
			owner->GridXPos -= 1;
			owner->sprite.setPosition(owner->GridYPos * 32, owner->GridXPos * 32); //TODO abstract this weird flipping out
		}
	}

	if (moveDir == Direction::SOUTH) {
		if (Game::activeLevel->layer2[owner->GridXPos + 1][owner->GridYPos].entityInNode != NULL
			&& Game::activeLevel->layer2[owner->GridXPos + 1][owner->GridYPos].entityInNode->hasCollision) {
			owner->OnCollision(*(Game::activeLevel->layer2[owner->GridXPos + 1][owner->GridYPos].entityInNode));
			owner->OnCollision(*(Game::activeLevel->layer1[owner->GridXPos + 1][owner->GridYPos].entityInNode));
			if (Game::activeLevel->layer2[owner->GridXPos + 1][owner->GridYPos].entityInNode->GetComponent("Push")) {
				Push* pushComp = dynamic_cast<Push*>(Game::activeLevel->layer2[owner->GridXPos + 1][owner->GridYPos].entityInNode->GetComponent("Push"));
				pushComp->TryToPush(moveDir);
			}
		}

		if (Game::activeLevel->layer2[owner->GridXPos + 1][owner->GridYPos].entityInNode == NULL && Game::activeLevel->layer1[owner->GridXPos + 1][owner->GridYPos].entityInNode->isWalkable) {
			//printf("Move successful!");
			Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos].entityInNode = NULL; //reset old pos to NULL
			Game::activeLevel->layer2[owner->GridXPos + 1][owner->GridYPos].entityInNode = owner;
			owner->GridXPos += 1;
			owner->sprite.setPosition(owner->GridYPos * 32, owner->GridXPos * 32);
		}
	}
	if (moveDir == Direction::WEST) {
		if (Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos - 1].entityInNode != NULL
			&& Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos - 1].entityInNode->hasCollision) {
			owner->OnCollision(*(Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos - 1].entityInNode));
			owner->OnCollision(*(Game::activeLevel->layer1[owner->GridXPos][owner->GridYPos - 1].entityInNode));
			if (Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos - 1].entityInNode->GetComponent("Push")) {
				Push* pushComp = dynamic_cast<Push*>(Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos - 1].entityInNode->GetComponent("Push"));
				pushComp->TryToPush(moveDir);
			}
		}
		if (Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos - 1].entityInNode == NULL && Game::activeLevel->layer1[owner->GridXPos][owner->GridYPos - 1].entityInNode->isWalkable) {
			//printf("Move successful!");
			Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos].entityInNode = NULL; //reset old pos to NULL
			Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos - 1].entityInNode = owner;
			owner->GridYPos -= 1;
			owner->sprite.setPosition(owner->GridYPos * 32, owner->GridXPos * 32);
		}
	}
	if (moveDir == Direction::EAST) {
		if (Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos + 1].entityInNode != NULL
			&& Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos + 1].entityInNode->hasCollision) {
			owner->OnCollision(*(Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos + 1].entityInNode));
			owner->OnCollision(*(Game::activeLevel->layer1[owner->GridXPos][owner->GridYPos + 1].entityInNode));
			if (Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos + 1].entityInNode->GetComponent("Push")) {
				Push* pushComp = dynamic_cast<Push*>(Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos + 1].entityInNode->GetComponent("Push"));
				pushComp->TryToPush(moveDir);
			}
		}
		if (Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos + 1].entityInNode == NULL && Game::activeLevel->layer1[owner->GridXPos][owner->GridYPos - 1].entityInNode->isWalkable) {
			//printf("Move successful!");
			Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos].entityInNode = NULL; //reset old pos to NULL
			Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos + 1].entityInNode = owner;
			owner->GridYPos += 1;
			owner->sprite.setPosition(owner->GridYPos * 32, owner->GridXPos * 32);
		}
	}

}
