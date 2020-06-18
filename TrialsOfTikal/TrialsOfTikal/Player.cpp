#include "Player.h"

Player::Player() {
	isWalkable = false;
	texture.loadFromFile("assets/player.png");
	sprite.setTexture(texture);
	//sprite.setPosition(10, 10);
}
