#include "PlayerMove.h"
#include "Game.h"
#include <iostream>


PlayerMove::PlayerMove(Entity& newOwner) : owner(&newOwner){
	name = "PlayerMove";
	//owner = &newOwner;
}

PlayerMove::PlayerMove() {

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
	if (moveDir == Direction::NORTH) {
		if (Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos-1].entityInNode == NULL && Game::activeLevel->layer1[owner->GridXPos][owner->GridYPos-1].entityInNode->isWalkable) {
			printf("Move successful!");
			Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos].entityInNode = NULL; //reset old pos to NULL
			Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos-1].entityInNode = owner;
			owner->GridYPos -= 1;
			owner->sprite.setPosition(owner->GridXPos * 32, owner->GridYPos * 32);
		}
	}
	if (moveDir == Direction::SOUTH) {
		if (Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos + 1].entityInNode == NULL && Game::activeLevel->layer1[owner->GridXPos][owner->GridYPos + 1].entityInNode->isWalkable) {
			printf("Move successful!");
			Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos].entityInNode = NULL; //reset old pos to NULL
			Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos + 1].entityInNode = owner;
			owner->GridYPos += 1;
			owner->sprite.setPosition(owner->GridXPos * 32, owner->GridYPos * 32);
		}
	}
	if (moveDir == Direction::WEST) {
		if (Game::activeLevel->layer2[owner->GridXPos-1][owner->GridYPos].entityInNode == NULL && Game::activeLevel->layer1[owner->GridXPos-1][owner->GridYPos].entityInNode->isWalkable) {
			printf("Move successful!");
			Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos].entityInNode = NULL; //reset old pos to NULL
			Game::activeLevel->layer2[owner->GridXPos-1][owner->GridYPos].entityInNode = owner;
			owner->GridXPos -= 1;
			owner->sprite.setPosition(owner->GridXPos * 32, owner->GridYPos * 32);
		}
	}
	if (moveDir == Direction::EAST) {
		if (Game::activeLevel->layer2[owner->GridXPos + 1][owner->GridYPos].entityInNode == NULL && Game::activeLevel->layer1[owner->GridXPos + 1][owner->GridYPos].entityInNode->isWalkable) {
			printf("Move successful!");
			Game::activeLevel->layer2[owner->GridXPos][owner->GridYPos].entityInNode = NULL; //reset old pos to NULL
			Game::activeLevel->layer2[owner->GridXPos + 1][owner->GridYPos].entityInNode = owner;
			owner->GridXPos += 1;
			owner->sprite.setPosition(owner->GridXPos * 32, owner->GridYPos * 32);
		}
	}

}
