#include "Player.h"
#include "PlayerMove.h"
#include "Game.h"
#include "Level.h"
#include <iostream>
#include "Push.h"
#include "ArtifactPickUp.h"
#include "Game.h"
//PlayerMove playerMove;
Player::Player() {
	//playerMove = PlayerMove();
	isWalkable = false;
	texture.loadFromFile("assets/player.png");
	sprite.setTexture(texture);
	//sprite.setPosition(10, 10);
	name = "Player";
	components.push_back(new PlayerMove(*this));
	components.push_back(new Push(*this));
	
}

void Player::OnCollision(Entity& other)
{

	//HACK: because of that exeption this is neded to delete an object on collision...ould maybe tag to die and kill stuff more often
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
