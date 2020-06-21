#include "Player.h"
#include "PlayerMove.h"
#include "Game.h"
#include "Level.h"
#include <iostream>
#include "Push.h"
#include "ArtifactPickUp.h"
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


}
