#ifndef NORMALROOMFACTORY_H
#define NORMALROOMFACTORY_H

#include "RoomFactory.h"

class NormalRoomFactory : public RoomFactory
{
	Room* createRoom();
};

#endif // !NORMALROOMFACTORY_H
