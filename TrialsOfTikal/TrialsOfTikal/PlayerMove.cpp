#include "PlayerMove.h"
#include "Game.h"
#include <iostream>
#include "Push.h"
#include "ArtifactPickUp.h"
#include "BreakTheFloor.h"
PlayerMove::PlayerMove(Entity& newOwner) : owner(&newOwner){
	name = "PlayerMove";
	//owner = &newOwner;
}



void PlayerMove::UpdateComponent()
{
	//printf("componentUpdated!");
	ReadInput();

}

void PlayerMove::ReadInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		TryToMove(Direction::NORTH);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		TryToMove(Direction::SOUTH);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		TryToMove(Direction::WEST);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		TryToMove(Direction::EAST);
	}
}

void PlayerMove::TryToMove(Direction::dirs moveDir)
{
	if (Game::activeLevel->layer1[owner->GridXPos][owner->GridYPos].entityInNode->GetComponent("BreakTheFloor")) {
		BreakTheFloor* btf = dynamic_cast<BreakTheFloor*>(Game::activeLevel->layer1[owner->GridXPos][owner->GridYPos].entityInNode->GetComponent("BreakTheFloor"));
		btf->UpdateBrokenStatus(*owner);
	}
	if (moveDir == Direction::NORTH) {
		//collide layer1
		if (Game::activeLevel->layer1[owner->GridXPos - 1][owner->GridYPos].entityInNode != NULL) {
			owner->OnCollision(*(Game::activeLevel->layer1[owner->GridXPos - 1][owner->GridYPos].entityInNode));
		}
		//collide layer2
		if (Game::activeLevel->layer2[owner->GridXPos - 1][owner->GridYPos].entityInNode != NULL) {
			owner->OnCollision(*(Game::activeLevel->layer2[owner->GridXPos - 1][owner->GridYPos].entityInNode));


		}
		if (Game::activeLevel->layer2[owner->GridXPos - 1][owner->GridYPos].entityInNode != NULL) {
			//push
			if (Game::activeLevel->layer2[owner->GridXPos - 1][owner->GridYPos].entityInNode->GetComponent("Push")) {
				Push* pushComp = dynamic_cast<Push*>(Game::activeLevel->layer2[owner->GridXPos - 1][owner->GridYPos].entityInNode->GetComponent("Push"));
				pushComp->TryToPush(moveDir);
			}
		}

		//Move
		if (Game::activeLevel->layer2[owner->GridXPos - 1][owner->GridYPos].entityInNode == NULL && Game::activeLevel->layer1[owner->GridXPos - 1][owner->GridYPos].entityInNode->isWalkable
			&& !(Game::activeLevel->layer1[owner->GridXPos - 1][owner->GridYPos].entityInNode->killOnContact)) {
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


		}
		if (Game::activeLevel->layer2[owner->GridXPos + 1][owner->GridYPos].entityInNode != NULL) {
			//push
			if (Game::activeLevel->layer2[owner->GridXPos + 1][owner->GridYPos].entityInNode->GetComponent("Push")) {
				Push* pushComp = dynamic_cast<Push*>(Game::activeLevel->layer2[owner->GridXPos + 1][owner->GridYPos].entityInNode->GetComponent("Push"));
				pushComp->TryToPush(moveDir);
			}

		}

		//Move
		if (Game::activeLevel->layer2[owner->GridXPos + 1][owner->GridYPos].entityInNode == NULL && Game::activeLevel->layer1[owner->GridXPos + 1][owner->GridYPos].entityInNode->isWalkable
			&& !(Game::activeLevel->layer1[owner->GridXPos + 1][owner->GridYPos].entityInNode->killOnContact)) {
			//printf("Move successful!");
			Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos].entityInNode = NULL; //reset old pos to NULL TODO: ABSTRACT THIS OUT
			Game::activeLevel->layer2[owner->GridXPos + 1][owner->GridYPos].entityInNode = owner;
			owner->GridXPos += 1;
			owner->sprite.setPosition(owner->GridYPos * 32, owner->GridXPos * 32); //TODO abstract this weird flipping out
		}
	}
	if (moveDir == Direction::WEST) {
		//collide layer1
		if (Game::activeLevel->layer1[owner->GridXPos][owner->GridYPos-1].entityInNode != NULL) {
			owner->OnCollision(*(Game::activeLevel->layer1[owner->GridXPos][owner->GridYPos-1].entityInNode));
		}
		//collide layer2
		if (Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos-1].entityInNode != NULL) {
			owner->OnCollision(*(Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos-1].entityInNode));


		}

		if (Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos - 1].entityInNode != NULL) {
			//push
			if (Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos - 1].entityInNode->GetComponent("Push")) {
				Push* pushComp = dynamic_cast<Push*>(Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos - 1].entityInNode->GetComponent("Push"));
				pushComp->TryToPush(moveDir);
			}


		}


		//Move
		if (Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos-1].entityInNode == NULL && Game::activeLevel->layer1[owner->GridXPos][owner->GridYPos-1].entityInNode->isWalkable
			&& !(Game::activeLevel->layer1[owner->GridXPos][owner->GridYPos-1].entityInNode->killOnContact)) {
			//printf("Move successful!");
			Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos].entityInNode = NULL; //reset old pos to NULL TODO: ABSTRACT THIS OUT
			Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos-1].entityInNode = owner;
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


		}
		
		if (Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos + 1].entityInNode != NULL) {
			//push
			if (Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos + 1].entityInNode->GetComponent("Push")) {
				Push* pushComp = dynamic_cast<Push*>(Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos + 1].entityInNode->GetComponent("Push"));
				pushComp->TryToPush(moveDir);
			}


		}


		//Move
		if (Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos + 1].entityInNode == NULL && Game::activeLevel->layer1[owner->GridXPos][owner->GridYPos + 1].entityInNode->isWalkable
			&& !(Game::activeLevel->layer1[owner->GridXPos][owner->GridYPos+1].entityInNode->killOnContact)) {
			//printf("Move successful!");
			Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos].entityInNode = NULL; //reset old pos to NULL TODO: ABSTRACT THIS OUT
			Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos+1].entityInNode = owner;
			owner->GridYPos += 1;
			owner->sprite.setPosition(owner->GridYPos * 32, owner->GridXPos * 32); //TODO abstract this weird flipping out
		}
	}

}
