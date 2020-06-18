#include "Box.h"

Box::Box() {
	isWalkable = false;
	texture.loadFromFile("assets/box.png");
	sprite.setTexture(texture);
	//sprite.setPosition(10, 10);
}