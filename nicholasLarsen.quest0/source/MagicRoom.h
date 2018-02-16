#ifndef MAGICROOM_H
#define MAGICROOM_H

#include "Room.h"


class MagicRoom : public Room
{
	Room* execute(RoomMap*, int&);
};


#endif // !MAGICROOM_H
