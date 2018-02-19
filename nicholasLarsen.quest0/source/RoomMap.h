#ifndef  ROOMMAP_H
#define  ROOMMAP_H

#include <map>
#include <string>
#include <random>
#include <algorithm>

class Room;
class RoomFactory;

class RoomMap
{
public:
	RoomMap();
	RoomMap(const char*);
	bool Initialize(const char* configFile);
	Room* findNext(Room*);
	void randomizeRooms();

private:
	std::map<std::string, RoomFactory*> roomLibrary;
	std::map<std::string, Room*> rooms;

	bool LoadLevel(const char* configFile);
};

#endif // ! ROOMMAP_H
