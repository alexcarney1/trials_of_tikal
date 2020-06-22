#pragma once
#include <SFML/Graphics.hpp>
#include "Component.h"
#include <string>

class Entity
{
public:
	//Game::activeLevel->LoadLevelFromFile("testLevel.txt"); // HOW TO GET A STATIC!
	std::vector<Component*> components;
	bool isWalkable;
	bool hasCollision;
	sf::Sprite sprite;
	sf::Texture texture;
	int GridXPos;
	int GridYPos;
	bool enabled = true;
	bool taggedToDie = false;
	bool killOnContact = false;
	std::string name;
	virtual void OnCollision(Entity& other) =0;
	Component *GetComponent(std::string compName) {
		for (Component *comp : components) {
			//printf(comp->name.c_str());
			if (comp->name.compare(compName) == 0) {
				return comp;
			}
		}
		
		return NULL;
	}

};

