#include "Monkey.h"
#include "PlayerMove.h"
#include "Push.h"
Monkey::Monkey()
{
	//playerMove = PlayerMove();
	isWalkable = false;
	texture.loadFromFile("assets/monkey.png");
	sprite.setTexture(texture);
	//sprite.setPosition(10, 10);
	name = "Monkey";
	components.push_back(new PlayerMove(*this));
	components.push_back(new Push(*this));
}

void Monkey::OnCollision(Entity& other)
{
}
