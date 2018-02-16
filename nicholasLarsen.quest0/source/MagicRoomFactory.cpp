#include "MagicRoomFactory.h"
#include "MagicRoom.h"
Room* MagicRoomFactory::createRoom()
{
	return new MagicRoom();
}