#include "Player.h"
#include "PlayerMove.h"
#include "Game.h"
#include "Level.h"
#include <iostream>
#include "Push.h"
//PlayerMove playerMove;
Player::Player() {
	//playerMove = PlayerMove();
	isWalkable = false;
	texture.loadFromFile("assets/player.png");
	sprite.setTexture(texture);
	//sprite.setPosition(10, 10);
	printf("hererere");
	name = "Player";
	std::cout << this->GridXPos << std::endl;
	
	components.push_back(new PlayerMove(*this));
	
}

void Player::OnCollision(Entity& other)
{
}
