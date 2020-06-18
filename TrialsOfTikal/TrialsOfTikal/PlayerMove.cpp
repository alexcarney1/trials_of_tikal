#include "PlayerMove.h"
#include "Game.h"


PlayerMove::PlayerMove() {

}

PlayerMove::PlayerMove(Entity &newOwner) {
	name = "PlayerMove";
	owner = &newOwner;
}



void PlayerMove::UpdateComponent()
{
	printf("componentUpdated!");
	ReadInput();

}

void PlayerMove::ReadInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		printf("Up PRESSED!!");
		Direction::dirs val = Direction::NORTH;
		TryToMove(val);
	}
}

void PlayerMove::TryToMove(Direction::dirs moveDir)
{
}
