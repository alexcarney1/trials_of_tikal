#include "Game.h"
#include <SFML/Graphics.hpp>
#include "Wall.h"
#include "Level.h"
#include "PlayerMove.h"
#include "Component.h"

//todo: change levels
Level* Game::activeLevel = new Level("assets/testLevel.txt");
Game::Game() : window(new sf::RenderWindow(sf::VideoMode(512, 512), "Trials of Tikal", sf::Style::Titlebar | sf::Style::Close)){
	
}

Game::~Game() {
	delete this->window;
}

void Game::Update() {
	//printf("tick");
	//if (activeLevel->player.GetComponent("PlayerMove") != NULL) {
	//	printf("player has move!");
	//}

	for (Component *comp : activeLevel->player.components) { //NOTE: object slicing was here. The components vector was holding Base classes, need a pointer to the derived classes to call overriden virtual functions
		//printf("player componenets updated");
		comp->UpdateComponent();
	}
	for (Component* comp : activeLevel->monkey.components) { //NOTE: object slicing was here. The components vector was holding Base classes, need a pointer to the derived classes to call overriden virtual functions
	//printf("player componenets updated");
		comp->UpdateComponent();
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
			else {
			}
		}
	}
	if (activeLevel->CheckLevelStatus()) {
		printf("LEVEL CLEARED!\n");
	}

}

void Game::Render() {
	//CLEAR

	this->window->clear(sf::Color::Blue);
	for (int r = 0; r < 16; r++) {
		for (int c = 0; c < 16; c++) {
			if (activeLevel->layer1[r][c].entityInNode != NULL) {
				this->window->draw(activeLevel->layer1[r][c].entityInNode->sprite);
			}
			if (activeLevel->layer2[r][c].entityInNode != NULL) {
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



