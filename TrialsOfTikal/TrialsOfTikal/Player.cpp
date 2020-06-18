#include "Player.h"
#include "PlayerMove.h"
#include "Game.h"
#include "Level.h"
PlayerMove playerMove;
Player::Player() {
	playerMove = PlayerMove(*this);
	isWalkable = false;
	texture.loadFromFile("assets/player.png");
	sprite.setTexture(texture);
	//sprite.setPosition(10, 10);
	components.push_back(&playerMove);
	
}
