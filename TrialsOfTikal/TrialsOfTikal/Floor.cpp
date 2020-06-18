#include "Floor.h"
Floor::Floor() {
	isWalkable = true;
	texture.loadFromFile("assets/floor.png");
	sprite.setTexture(texture);
	//sprite.setPosition(10, 10);
	name = "Floor";
}
