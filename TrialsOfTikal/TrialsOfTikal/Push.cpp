#include "Push.h"

Push::Push(Entity& newOwner) : owner(&newOwner)
{
	name = "Push";
}

void Push::UpdateComponent()
{
}

//SLIGHLTY DIFFERENT FORM PLAYER OMVE BECAUSE IT CAN BE ON A KILLABLE SURFACE!
//not checking all layers here. oops.
void Push::TryToPush(Direction::dirs moveDir)
{
	if (moveDir == Direction::NORTH) {
		//collide layer1
		if (Game::activeLevel->layer1[owner->GridXPos - 1][owner->GridYPos].entityInNode != NULL) {
			owner->OnCollision(*(Game::activeLevel->layer1[owner->GridXPos - 1][owner->GridYPos].entityInNode));
		}
		//collide layer2
		if (Game::activeLevel->layer2[owner->GridXPos - 1][owner->GridYPos].entityInNode != NULL) {
			owner->OnCollision(*(Game::activeLevel->layer2[owner->GridXPos - 1][owner->GridYPos].entityInNode));

			//push
			if (Game::activeLevel->layer2[owner->GridXPos - 1][owner->GridYPos].entityInNode->GetComponent("Push")) {
				Push* pushComp = dynamic_cast<Push*>(Game::activeLevel->layer2[owner->GridXPos - 1][owner->GridYPos].entityInNode->GetComponent("Push"));
				pushComp->TryToPush(moveDir);
			}
		}

		//Move
		if (Game::activeLevel->layer2[owner->GridXPos - 1][owner->GridYPos].entityInNode == NULL && Game::activeLevel->layer1[owner->GridXPos - 1][owner->GridYPos].entityInNode->isWalkable) {
			//printf("Move successful!");
			Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos].entityInNode = NULL; //reset old pos to NULL TODO: ABSTRACT THIS OUT
			Game::activeLevel->layer2[owner->GridXPos - 1][owner->GridYPos].entityInNode = owner;
			owner->GridXPos -= 1;
			owner->sprite.setPosition(owner->GridYPos * 32, owner->GridXPos * 32); //TODO abstract this weird flipping out
		}
	}

	if (moveDir == Direction::SOUTH) {
		//collide layer1
		if (Game::activeLevel->layer1[owner->GridXPos + 1][owner->GridYPos].entityInNode != NULL) {
			owner->OnCollision(*(Game::activeLevel->layer1[owner->GridXPos + 1][owner->GridYPos].entityInNode));


		}

		//collide layer2
		if (Game::activeLevel->layer2[owner->GridXPos + 1][owner->GridYPos].entityInNode != NULL) {
			owner->OnCollision(*(Game::activeLevel->layer2[owner->GridXPos + 1][owner->GridYPos].entityInNode));

			//push
			if (Game::activeLevel->layer2[owner->GridXPos + 1][owner->GridYPos].entityInNode->GetComponent("Push")) {
				Push* pushComp = dynamic_cast<Push*>(Game::activeLevel->layer2[owner->GridXPos + 1][owner->GridYPos].entityInNode->GetComponent("Push"));
				pushComp->TryToPush(moveDir);
			}
		}

		//Move
		if (Game::activeLevel->layer2[owner->GridXPos + 1][owner->GridYPos].entityInNode == NULL && Game::activeLevel->layer1[owner->GridXPos + 1][owner->GridYPos].entityInNode->isWalkable) {
			//printf("Move successful!");
			Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos].entityInNode = NULL; //reset old pos to NULL TODO: ABSTRACT THIS OUT
			Game::activeLevel->layer2[owner->GridXPos + 1][owner->GridYPos].entityInNode = owner;
			owner->GridXPos += 1;
			owner->sprite.setPosition(owner->GridYPos * 32, owner->GridXPos * 32); //TODO abstract this weird flipping out
		}
	}
	if (moveDir == Direction::WEST) {
		//collide layer1
		if (Game::activeLevel->layer1[owner->GridXPos][owner->GridYPos - 1].entityInNode != NULL) {
			owner->OnCollision(*(Game::activeLevel->layer1[owner->GridXPos][owner->GridYPos - 1].entityInNode));
		}
		//collide layer2
		if (Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos - 1].entityInNode != NULL) {
			owner->OnCollision(*(Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos - 1].entityInNode));

			//push
			if (Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos - 1].entityInNode->GetComponent("Push")) {
				Push* pushComp = dynamic_cast<Push*>(Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos - 1].entityInNode->GetComponent("Push"));
				pushComp->TryToPush(moveDir);
			}
		}

		//Move
		if (Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos - 1].entityInNode == NULL && Game::activeLevel->layer1[owner->GridXPos][owner->GridYPos - 1].entityInNode->isWalkable) {
			//printf("Move successful!");
			Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos].entityInNode = NULL; //reset old pos to NULL TODO: ABSTRACT THIS OUT
			Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos - 1].entityInNode = owner;
			owner->GridYPos -= 1;
			owner->sprite.setPosition(owner->GridYPos * 32, owner->GridXPos * 32); //TODO abstract this weird flipping out
		}
	}
	if (moveDir == Direction::EAST) {
		//collide layer1
		if (Game::activeLevel->layer1[owner->GridXPos][owner->GridYPos + 1].entityInNode != NULL) {
			owner->OnCollision(*(Game::activeLevel->layer1[owner->GridXPos][owner->GridYPos + 1].entityInNode));
		}
		//collide layer2
		if (Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos + 1].entityInNode != NULL) {
			owner->OnCollision(*(Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos + 1].entityInNode));

			//push
			if (Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos + 1].entityInNode->GetComponent("Push")) {
				Push* pushComp = dynamic_cast<Push*>(Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos + 1].entityInNode->GetComponent("Push"));
				pushComp->TryToPush(moveDir);
			}
		}

		//Move
		if (Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos + 1].entityInNode == NULL && Game::activeLevel->layer1[owner->GridXPos][owner->GridYPos + 1].entityInNode->isWalkable) {
			//printf("Move successful!");
			Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos].entityInNode = NULL; //reset old pos to NULL TODO: ABSTRACT THIS OUT
			Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos + 1].entityInNode = owner;
			owner->GridYPos += 1;
			owner->sprite.setPosition(owner->GridYPos * 32, owner->GridXPos * 32); //TODO abstract this weird flipping out
		}
	}

}
