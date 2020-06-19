#pragma once
#include <string>
#include "Node.h"
#include "Player.h"
class Level
{
public: Level(std::string FName);
	  Node layer1[16][16]; //i think this uses default consttrucor
	  Node layer2[16][16];
	  void LoadLevelFromFile(std::string FName);
	  Player player;
};

