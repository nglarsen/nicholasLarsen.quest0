#include <iostream>
#include <string>
#include "Room.h"
#include "RoomFactory.h"
#include "RoomMap.h"
#include "ThirdParty\tinyxml\tinystr.h"
#include "ThirdParty\tinyxml\tinyxml.h"


void clearConsole();
void pauseConsole();
void splashScreen();

//Engine Functions
bool isGameDone(Room*, int);
void displayGameDone(Room*, int);

int main()
{
	//Declare Game Space
	RoomMap* map = NULL;
	Room* room = NULL;
	int health = -1;


	//Was having issues with configFile not taking the relative path.
	const char* configFile("D:\\Users\\Skath1x\\Documents\\GitHub\\nicholasLarsen.quest0\\nicholasLarsen.quest0\\Config\\puzzle.xml");
	//const char* configFile("..\\Config\\puzzle.xml");
	std::cout << configFile;
	//Initialize Resource Management
	map = new RoomMap();
	map->Initialize(configFile);

	//Initialize Game State
	room = map->findNext(room);
	health = 10;

	//Splash Screen
	clearConsole();
	splashScreen();

	while (!isGameDone(room, health))
	{
		//wipe the GUI
		clearConsole();

		//perform the game mechanic
		room = room->execute(map, health);
	}
	//EndGame State
	displayGameDone(room, health);

	return 0;
}

void clearConsole()
{
	system("cls");
}

void pauseConsole()
{
	system("pause");
}

void splashScreen()
{
	std::cout << "ROOM PUZZLE" << std::endl;
	std::cout << std::endl;
	std::cout << "Nicholas Larsen(2018)" << std::endl;
	std::cout << "CPSC 4399/5399, Advanced Game Programming, Quest 0";
	std::cout << "UALR, Computer Science Dept." << std::endl;
	std::cout << std::endl;
	std::cout << "INSTRUCTIONS: FIND THE FINISH" << std::endl << std::endl;
	pauseConsole();
}

void displayGameDone(Room* room, int health)
{
	if (health <= 0)
	{
		std::cout << std::endl;
		std::cout << "GAME OVER..." << std::endl;
		std::cout << std::endl;
	}
	else
	{
		switch (room->getCondition())
		{
		case WIN:
			std::cout << std::endl;
			std::cout << "YOU WIN" << std::endl;
			break;
		case LOSE:
			std::cout << std::endl << "YOU LOSE" << std::endl << std::endl;
			break;
		case QUIT:
			std::cout << std::endl << "GOOD BYE" << std::endl << std::endl;
			break;
		}
	}
	pauseConsole();
}

bool isGameDone(Room* room, int health)
{
	if (room->finish() || health < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}