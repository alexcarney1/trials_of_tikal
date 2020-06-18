#pragma once
#include <SFML/Graphics.hpp>
#include "Level.h"
class Game
{
public: 
	  sf::RenderWindow* window;
	  sf::Event event;
	  static Level* activeLevel;
	  Game();
	  ~Game();
	  void Render();
	  void Update();
};

