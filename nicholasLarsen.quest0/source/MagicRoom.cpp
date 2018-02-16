#include "MagicRoom.h"
#include "RoomMap.h"

Room* MagicRoom::execute(RoomMap* pRoomMap, int& hp)
{
	pRoomMap->randomizeRooms();
	//Print HUD
	std::cout << "View:   " << this->description << std::endl;
	std::cout << "Health: " << hp << std::endl;
	std::cout << "Available Moves: ";
	//Print moves
	for (std::map<std::string, std::string>::iterator it = neighbors.begin(); it != neighbors.end(); ++it)
	{
		std::cout << it->first << " ";
	}
	//Get Transition
	bool moving = true;
	while (moving)
	{
		std::cout << "\nSelect Move: ";
		std::string nextString;
		std::cin >> nextString;
		if (neighbors.find(nextString) != neighbors.end())
		{
			moving = false;
			transition = nextString;
		}
		else
			std::cout << "Try again\n";
	}
	//Increase Health
	hp+= 2;
	return pRoomMap->findNext(this);
}