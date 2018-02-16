#include "NormalRoomFactory.h"
#include "NormalRoom.h"

Room* NormalRoomFactory::createRoom()
{
	return new NormalRoom();
}