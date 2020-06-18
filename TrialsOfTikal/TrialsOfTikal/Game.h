#pragma once
#include <SFML/Graphics.hpp>
class Game
{
public: 
	  sf::RenderWindow* window;
	  sf::Event event;
	  Game();
	  ~Game();
	  void Render();
	  void Update();
};

