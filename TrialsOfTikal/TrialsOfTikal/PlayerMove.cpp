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
		TryToMove(Direction::NORTH);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		printf("Down PRESSED!!");
		TryToMove(Direction::SOUTH);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		printf("LEft PRESSED!!");
		TryToMove(Direction::WEST);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		printf("RIGHT PRESSED!!");
		TryToMove(Direction::EAST);
	}
}

void PlayerMove::TryToMove(Direction::dirs moveDir)
{
}
