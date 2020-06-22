#include "Level.h"
#include <fstream>
#include "Floor.h"
#include "Wall.h"
#include "Player.h"
#include "Goal.h"
#include "Box.h"
#include <iostream>
#include "GoalBehavior.h"
#include "Lava.h"
#include "Artifact.h"
char wallChar = '#';
char floorChar = '.';
char playerChar = 'p';
char goalChar = 'g';
char boxChar = 'b';
char lavaChar = 'l';
char monkeyChar = 'm';
char artifactChar = 'a';

Level::Level(std::string FName) : player(Player()),numGoals(0), monkey(Monkey()), numArtifactsCollected(0) {
	LoadLevelFromFile(FName);
	CheckLevelStatus();
	
}

void Level::LoadLevelFromFile(std::string FName) {
	std::ifstream myfile;
	myfile.open(FName);
	std::string fileLine;
	int r = 0;
	while (getline(myfile, fileLine)) { //while there is a line
		for (int c = 0; c < fileLine.size(); c++) { // for each character in rowstring

			if (fileLine[c] == wallChar) {
				layer1[r][c].entityInNode = new Wall();
				layer1[r][c].xPos = r; layer1[r][c].yPos = c;
				layer1[r][c].entityInNode->sprite.setPosition(c*16, r*16);
				layer1[r][c].entityInNode->GridXPos = r;
				layer1[r][c].entityInNode->GridYPos = c;
				layer2[r][c].entityInNode = NULL; //empty...
				layer2[r][c].xPos = r; layer2[r][c].yPos = c;
			}
			else if (fileLine[c] == lavaChar) {
				layer1[r][c].entityInNode = new Lava();
				layer1[r][c].xPos = r; layer1[r][c].yPos = c;
				layer1[r][c].entityInNode->sprite.setPosition(c * 16, r * 16);
				layer1[r][c].entityInNode->GridXPos = r;
				layer1[r][c].entityInNode->GridYPos = c;
				layer2[r][c].entityInNode = NULL; //empty...
				layer2[r][c].xPos = r; layer2[r][c].yPos = c;
			}
			else if (fileLine[c] == floorChar) {
				layer1[r][c] = Node();
				layer1[r][c].entityInNode = new Floor();
				layer1[r][c].xPos = r; layer1[r][c].yPos = c;
				layer1[r][c].entityInNode->sprite.setPosition(c*16, r*16);
				layer1[r][c].entityInNode->GridXPos = r;
				layer1[r][c].entityInNode->GridYPos = c;
				layer2[r][c] = Node();
				layer2[r][c].entityInNode = NULL; //empty...
				layer2[r][c].xPos = r; layer2[r][c].yPos = c;
			}
			else if (fileLine[c] == goalChar) {
				layer1[r][c] = Node();
				layer1[r][c].entityInNode = new Goal();
				layer1[r][c].xPos = r; layer1[r][c].yPos = c;
				layer1[r][c].entityInNode->sprite.setPosition(c*16, r*16);
				layer1[r][c].entityInNode->GridXPos = r;
				layer1[r][c].entityInNode->GridYPos = c;
				layer2[r][c] = Node();
				layer2[r][c].entityInNode = NULL; //empty...
				layer2[r][c].xPos = r; layer2[r][c].yPos = c;
				numGoals += 1;
			}
			else if (fileLine[c] == artifactChar) {
				layer1[r][c] = Node();
				layer1[r][c].entityInNode = new Floor();
				layer1[r][c].xPos = r; layer1[r][c].yPos = c;
				layer1[r][c].entityInNode->sprite.setPosition(c * 16, r * 16);
				layer1[r][c].entityInNode->GridXPos = r;
				layer1[r][c].entityInNode->GridYPos = c;
				layer2[r][c] = Node();
				layer2[r][c].entityInNode = new Artifact(); //empty...
				layer2[r][c].entityInNode->sprite.setPosition(c * 16, r * 16);
				layer2[r][c].entityInNode->GridXPos = r;
				layer2[r][c].entityInNode->GridYPos = c;
				layer2[r][c].xPos = r; layer2[r][c].yPos = c;
				numArtifacts += 1;
			}
			else if (fileLine[c] == boxChar) {
				layer1[r][c] = Node();
				layer1[r][c].entityInNode = new Floor();
				layer1[r][c].xPos = r; layer1[r][c].yPos = c;
				layer1[r][c].entityInNode->sprite.setPosition(c*16, r*16);
				layer1[r][c].entityInNode->GridXPos = r;
				layer1[r][c].entityInNode->GridYPos = c;
				layer2[r][c] = Node();
				layer2[r][c].entityInNode = new Box(); //empty...
				layer2[r][c].xPos = r; layer2[r][c].yPos = c;
				layer2[r][c].entityInNode->sprite.setPosition(c*16, r*16);
				layer2[r][c].entityInNode->GridXPos = r;
				layer2[r][c].entityInNode->GridYPos = c;
			}
			else if (fileLine[c] == playerChar) { //TODO : place player obj, dont instantiate...maybe..
				layer1[r][c].entityInNode = new Floor();
				layer1[r][c].xPos = r; layer1[r][c].yPos = c;
				layer1[r][c].entityInNode->sprite.setPosition(c*16, r*16);
				layer1[r][c].entityInNode->GridXPos = r;
				layer1[r][c].entityInNode->GridYPos = c;
				layer2[r][c].entityInNode = &player; //empty...
				layer2[r][c].xPos = r; layer2[r][c].yPos = c;
				layer2[r][c].entityInNode->sprite.setPosition(c * 16, r * 16);
				layer2[r][c].entityInNode->GridXPos = r;
				layer2[r][c].entityInNode->GridYPos = c;
				player.enabled = true;
			}
			else if (fileLine[c] == monkeyChar) { //TODO : place player obj, dont instantiate...maybe..
				layer1[r][c].entityInNode = new Floor();
				layer1[r][c].xPos = r; layer1[r][c].yPos = c;
				layer1[r][c].entityInNode->sprite.setPosition(c * 16, r * 16);
				layer1[r][c].entityInNode->GridXPos = r;
				layer1[r][c].entityInNode->GridYPos = c;
				layer2[r][c].entityInNode = &monkey; //empty...
				layer2[r][c].xPos = r; layer2[r][c].yPos = c;
				layer2[r][c].entityInNode->sprite.setPosition(c * 16, r * 16);
				layer2[r][c].entityInNode->GridXPos = r;
				layer2[r][c].entityInNode->GridYPos = c;
				monkey.enabled = false;
			}
		}
		r++;
	}

}

bool Level::CheckLevelStatus()
{
	int numGoalsCovered = 0;
	for (int r = 0; r < 16; r++) {
		for (int c = 0; c < 16; c++) {
			if (layer1[r][c].entityInNode != NULL && layer1[r][c].entityInNode->GetComponent("GoalBehavior") != NULL) {
				//printf("in here");
				GoalBehavior* goalBehavior = dynamic_cast<GoalBehavior*>(layer1[r][c].entityInNode->GetComponent("GoalBehavior"));
				if (goalBehavior->isCovered) {
					numGoalsCovered += 1;
				}
			}
		}
	}
	if (numGoalsCovered == numGoals && numArtifactsCollected == numArtifacts) {
		return true;
	}

	return false;
}
