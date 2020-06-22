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
	  void ReadMasterInput();
	  void Render();
	  void Update();
	  void PostUpdate();
	  static void ResetLevel();
};

