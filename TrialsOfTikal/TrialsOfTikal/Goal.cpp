#include "Goal.h"

Goal::Goal() {
	isWalkable = false;
	texture.loadFromFile("assets/goal.png");
	sprite.setTexture(texture);
	//sprite.setPosition(10, 10);
}
