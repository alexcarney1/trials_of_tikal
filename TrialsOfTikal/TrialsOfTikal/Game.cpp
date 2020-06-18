#include "Game.h"
#include <SFML/Graphics.hpp>
#include "Wall.h"
#include "Level.h"

Level activeLevel = Level("assets/testLevel.txt");
Game::Game() {
	this->window = new sf::RenderWindow(sf::VideoMode(920, 720), "Trials of Tikal");
}

Game::~Game() {
	delete this->window;
}

void Game::Update() {
	//printf("tick");
}

void Game::Render() {
	//CLEAR
	this->window->clear(sf::Color::Blue);
	for (int r = 0; r < 16; r++) {
		for (int c = 0; c < 16; c++) {
			if (activeLevel.layer1[r][c].entityInNode != NULL) {
				this->window->draw(activeLevel.layer1[r][c].entityInNode->sprite);
			}
			if (activeLevel.layer2[r][c].entityInNode != NULL) {
				this->window->draw(activeLevel.layer2[r][c].entityInNode->sprite);
			}
			else {
			}

		}
	}


	//this->window->draw(wall.sprite);

	//display
	this->window->display();
	
}



