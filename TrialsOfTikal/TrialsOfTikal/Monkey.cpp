#include "Monkey.h"
#include "PlayerMove.h"
Monkey::Monkey()
{
	//playerMove = PlayerMove();
	isWalkable = false;
	texture.loadFromFile("assets/monkey.png");
	sprite.setTexture(texture);
	//sprite.setPosition(10, 10);
	name = "Monkey";
	components.push_back(new PlayerMove(*this));
}

void Monkey::OnCollision(Entity& other)
{
}
