#include "Level.h"
#include <fstream>
#include "Floor.h";
#include "Wall.h";
#include "Player.h";
#include "Goal.h";
#include "Box.h";
#include <iostream>

char wallChar = '#';
char floorChar = '.';
char playerChar = 'p';
char goalChar = 'g';
char boxChar = 'b';


Level::Level(std::string FName) {
	LoadLevelFromFile(FName);

}


void Level::LoadLevelFromFile(std::string FName) {
	std::ifstream myfile;
	myfile.open(FName);
	std::string fileLine;
	int r = 0;
	while (getline(myfile, fileLine)) { //while there is a line
		for (int c = 0; c < fileLine.size(); c++) { // for each character in rowstring

			if (fileLine[c] == wallChar) {
				//printf("#");
				//layer1[r][c] = Node();
				layer1[r][c].entityInNode = new Wall();
				layer1[r][c].xPos = r; layer1[r][c].yPos = c;
				layer1[r][c].entityInNode->sprite.setPosition(r*32, c*32);
				layer1[r][c].entityInNode->GridXPos = r;
				layer1[r][c].entityInNode->GridYPos = c;
				//layer2[r][c] = Node();
				layer2[r][c].entityInNode = NULL; //empty...
				layer2[r][c].xPos = r; layer2[r][c].yPos = c;
			}
			else if (fileLine[c] == floorChar) {
				//printf(".");
				layer1[r][c] = Node();
				layer1[r][c].entityInNode = new Floor();
				layer1[r][c].xPos = r; layer1[r][c].yPos = c;
				layer1[r][c].entityInNode->sprite.setPosition(r*32, c*32);
				layer1[r][c].entityInNode->GridXPos = r;
				layer1[r][c].entityInNode->GridYPos = c;
				layer2[r][c] = Node();
				layer2[r][c].entityInNode = NULL; //empty...
				layer2[r][c].xPos = r; layer2[r][c].yPos = c;
			}
			else if (fileLine[c] == goalChar) {
				//printf("g");
				layer1[r][c] = Node();
				layer1[r][c].entityInNode = new Goal();
				layer1[r][c].xPos = r; layer1[r][c].yPos = c;
				layer1[r][c].entityInNode->sprite.setPosition(r*32, c*32);
				layer1[r][c].entityInNode->GridXPos = r;
				layer1[r][c].entityInNode->GridYPos = c;
				layer2[r][c] = Node();
				layer2[r][c].entityInNode = NULL; //empty...
				layer2[r][c].xPos = r; layer2[r][c].yPos = c;
			}
			else if (fileLine[c] == boxChar) {
				//printf("b");
				layer1[r][c] = Node();
				layer1[r][c].entityInNode = new Floor();
				layer1[r][c].xPos = r; layer1[r][c].yPos = c;
				layer1[r][c].entityInNode->sprite.setPosition(r*32, c*32);
				layer1[r][c].entityInNode->GridXPos = r;
				layer1[r][c].entityInNode->GridYPos = c;
				layer2[r][c] = Node();
				layer2[r][c].entityInNode = new Box(); //empty...
				layer2[r][c].xPos = r; layer2[r][c].yPos = c;
				layer2[r][c].entityInNode->sprite.setPosition(r*32, c*32);
				layer2[r][c].entityInNode->GridXPos = r;
				layer2[r][c].entityInNode->GridYPos = c;
			}
			else if (fileLine[c] == playerChar) { //TODO : place player obj, dont instantiate...maybe..
				//printf("p");
				//layer1[r][c] = Node();
				layer1[r][c].entityInNode = new Floor();
				layer1[r][c].xPos = r; layer1[r][c].yPos = c;
				layer1[r][c].entityInNode->sprite.setPosition(r*32, c*32);
				layer1[r][c].entityInNode->GridXPos = r;
				//std::cout << layer1[r][c].entityInNode->GridXPos << std::endl;
				layer1[r][c].entityInNode->GridYPos = c;
				//layer2[r][c] = Node();
				layer2[r][c].entityInNode = &player; //empty...
				
				layer2[r][c].xPos = r; layer2[r][c].yPos = c;
				layer2[r][c].entityInNode->sprite.setPosition(r * 32, c * 32);
				layer2[r][c].entityInNode->GridXPos = r;
				//std::cout << layer1[r][c].entityInNode->GridXPos << std::endl;
				layer2[r][c].entityInNode->GridYPos = c;
				//std::cout << layer1[r][c].entityInNode->GridYPos << std::endl;

			}




		}
		r++;
	}
}
