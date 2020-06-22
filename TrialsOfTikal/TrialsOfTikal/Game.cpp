#include "Game.h"
#include <SFML/Graphics.hpp>
#include "Wall.h"
#include "Level.h"
#include "PlayerMove.h"
#include "Component.h"
#include "GoalBehavior.h"
//todo: change levels
Level* Game::activeLevel = new Level("assets/testLevel.txt");
Game::Game() : window(new sf::RenderWindow(sf::VideoMode(768, 768), "Trials of Tikal", sf::Style::Titlebar | sf::Style::Close)){
	window->setFramerateLimit(20);
}

Game::~Game() {
	delete this->window;
}

void Game::ReadMasterInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
	{
		activeLevel->player.enabled = false;
		activeLevel->monkey.enabled = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		activeLevel->player.enabled = true;
		activeLevel->monkey.enabled = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		ResetLevel();
		
	}

}

void Game::Update() {

	if (activeLevel->player.enabled) {
		for (Component* comp : activeLevel->player.components) { //NOTE: object slicing was here. The components vector was holding Base classes, need a pointer to the derived classes to call overriden virtual functions
			comp->UpdateComponent();
		}
	}
	if (activeLevel->monkey.enabled) {
		for (Component* comp : activeLevel->monkey.components) { //NOTE: object slicing was here. The components vector was holding Base classes, need a pointer to the derived classes to call overriden virtual functions
			comp->UpdateComponent();
		}
	}


	//TODO: boxes then goals. for now all at once.
	for (int r = 0; r < 16; r++) {
		for (int c = 0; c < 16; c++) {
			if (activeLevel->layer1[r][c].entityInNode != NULL && !(activeLevel->layer1[r][c].entityInNode->GetComponent("PlayerMove"))) {
				for (Component* comp : activeLevel->layer1[r][c].entityInNode->components) {
					comp->UpdateComponent();
				}
			}
			if (activeLevel->layer2[r][c].entityInNode != NULL && !(activeLevel->layer2[r][c].entityInNode->GetComponent("PlayerMove"))) {
				for (Component* comp : activeLevel->layer2[r][c].entityInNode->components) {
					comp->UpdateComponent();
				}
			}
		}
	}
	PostUpdate();



}

void Game::PostUpdate() {
	for (int r = 0; r < 16; r++) {
		for (int c = 0; c < 16; c++) {
			if (activeLevel->layer1[r][c].entityInNode != NULL && activeLevel->layer1[r][c].entityInNode->taggedToDie) {
				activeLevel->layer1[r][c].entityInNode = NULL;

				//Hack .Updating goal positions again because now they might not be covered after a move. Could do boxes, then goals in a later build
				if (activeLevel->layer1[r][c].entityInNode != NULL && activeLevel->layer1[r][c].entityInNode->GetComponent("GoalBehavior") != NULL) {
					//printf("in here");
					GoalBehavior* goalBehavior = dynamic_cast<GoalBehavior*>(activeLevel->layer1[r][c].entityInNode->GetComponent("GoalBehavior"));
					goalBehavior->UpdateComponent();
				}
			}
			if (activeLevel->layer2[r][c].entityInNode != NULL && activeLevel->layer2[r][c].entityInNode->taggedToDie) {
				activeLevel->layer2[r][c].entityInNode = NULL;
			}
		}
	}
	if (activeLevel->CheckLevelStatus()) {
		printf("LEVEL CLEARED!\n");
	}
	if (activeLevel->player.taggedToDie) {
		ResetLevel();
	}
	else if (activeLevel->monkey.taggedToDie) {
		ResetLevel();
	}

}

void Game::ResetLevel()
{
	activeLevel = new Level("assets/testLevel.txt");
}

void Game::Render() {
	//CLEAR
	ReadMasterInput();
	this->window->clear(sf::Color::Blue);
	for (int r = 0; r < 16; r++) {
		for (int c = 0; c < 16; c++) {
			if (activeLevel->layer1[r][c].entityInNode != NULL) {
				activeLevel->layer1[r][c].entityInNode->sprite.setScale(3,3);
				activeLevel->layer1[r][c].entityInNode->sprite.setPosition(c * 48, r * 48);
				this->window->draw(activeLevel->layer1[r][c].entityInNode->sprite);
			}
			if (activeLevel->layer2[r][c].entityInNode != NULL) {
				activeLevel->layer2[r][c].entityInNode->sprite.setScale(3, 3);
				activeLevel->layer2[r][c].entityInNode->sprite.setPosition(c * 48, r * 48);
				this->window->draw(activeLevel->layer2[r][c].entityInNode->sprite);
			}
			else {
			}
		}
	}



	//this->window->draw(wall.sprite);

	//display
	this->window->display();
	
}



