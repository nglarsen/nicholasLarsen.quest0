#ifndef ROOMFACTORY_H
#define ROOMFACTORY_H

class Room;

class RoomFactory
{
public:
	virtual Room* createRoom() = 0;
};

#endif // !ROOMFACTORY_H
