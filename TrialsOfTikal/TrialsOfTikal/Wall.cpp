#include "Wall.h"

Wall::Wall() {
	isWalkable = false;
	texture.loadFromFile("assets/wall.png");
	sprite.setTexture(texture);
	//sprite.setPosition(10, 10);
}
