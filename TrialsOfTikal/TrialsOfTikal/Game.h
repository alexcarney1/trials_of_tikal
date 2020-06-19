#pragma once
#include <SFML/Graphics.hpp>
#include "Level.h"
class Game
{
public: 
	  sf::RenderWindow* window;
	  static Level* activeLevel;
	  Game();
	  ~Game();
	  void Render();
	  void Update();
};

