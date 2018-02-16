#ifndef NORMALROOM_H
#define NORMALROOM_H

#include "Room.h"


class NormalRoom : public Room
{
	Room* execute(RoomMap*, int&);
};


#endif // !NORMALROOM_H
