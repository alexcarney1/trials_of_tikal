#include "Goal.h"
#include "GoalBehavior.h"
Goal::Goal() {
	isWalkable = true;
	hasCollision = false;
	name = "Goal";
	texture.loadFromFile("assets/goal.png");
	sprite.setTexture(texture);
	//sprite.setPosition(10, 10);
	components.push_back(new GoalBehavior(*this));
}

void Goal::OnCollision(Entity& other)
{
}
