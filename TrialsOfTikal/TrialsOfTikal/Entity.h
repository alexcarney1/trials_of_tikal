#pragma once
#include <SFML/Graphics.hpp>
class Entity
{
public:
	
	bool isWalkable;
	sf::Sprite sprite;
	sf::Texture texture;
	void GetComponents(); //tODO: Get the components!

};

