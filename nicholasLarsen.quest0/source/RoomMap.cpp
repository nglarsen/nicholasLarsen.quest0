#include "RoomMap.h"
#include "NormalRoomFactory.h"
#include "MagicRoomFactory.h"
#include "Room.h"

RoomMap::RoomMap()
{
	roomLibrary["Normal"] = new NormalRoomFactory;
	roomLibrary["Magic"] = new MagicRoomFactory;
}

RoomMap::RoomMap(const char* configFile)
{
	Initialize(configFile);
}

bool RoomMap::Initialize(const char* configFile)
{
	roomLibrary["Normal"] = new NormalRoomFactory;
	roomLibrary["Magic"] = new MagicRoomFactory;


	if (LoadLevel(configFile))
		return true;
	else
		return false;
	
}

Room* RoomMap::findNext(Room* nextRoom)
{
	if (nextRoom == NULL)
		return rooms.find("start")->second;
	

	return rooms.find(nextRoom->next())->second;
}

bool RoomMap::LoadLevel(const char* configFile)
{
	TiXmlDocument doc(configFile);
	doc.LoadFile();

	TiXmlElement* root = doc.FirstChildElement("Puzzle");
	TiXmlElement* pElem;
	pElem = root->FirstChildElement("Room");

	while (pElem)
	{
		
		Room* pRoom = roomLibrary[pElem->Attribute("type")]->createRoom();
		pRoom->Initialize(pElem);
		rooms[pElem->Attribute("name")]= pRoom;
		pElem = pElem->NextSiblingElement();

	}

	if (rooms.size() > 0)
		return true;
	else
		return false;
}

void RoomMap::randomizeRooms()
{
	//Create a vector to store the rooms in
	std::vector<Room*> roomShuffle;
	std::default_random_engine randomEngine;
	//cycle through rooms and fill array with identifiers
	for (std::map<std::string, Room*>::iterator it=rooms.begin(); it != rooms.end(); it++)
	{
		roomShuffle.push_back(it->second);
	}
	
	//shuffle vector roomShuffle
	std::shuffle(roomShuffle.begin(), roomShuffle.end(), randomEngine);

	//iterate through rooms setting the new identifiers (This code should be very similar to the first for loop)
	//Reset the counter because idk how to do it in the for setup, I know you can though.
	
	/*for (std::map<std::string, Room*>::iterator it = rooms.begin(); it != rooms.end(); it++)
	{
		rooms[it->first] = roomShuffle[counter];
		counter++;
	}*/

	//Gonna have some fun with std::pair to solve my unnecessary int counter variable problem
	for (std::pair<std::map<std::string, Room*>::iterator,int> p(rooms.begin(),0); p.first != rooms.end(); p.first++,p.second++)
	{
		rooms[p.first->first] = roomShuffle[p.second];
	}
}