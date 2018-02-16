#ifndef ROOM_H
#define ROOM_H

#include "ThirdParty\tinyxml\tinystr.h"
#include "ThirdParty\tinyxml\tinyxml.h"
#include "definitions.h"
#include <string>
#include <map>
#include <iostream>
#include <sstream>

class RoomMap;

class Room
{
public:
	Room();
	Room(TiXmlElement*);
	~Room();
	bool Initialize(TiXmlElement*);
	virtual Room* execute(RoomMap*, int &) = 0;
	bool finish();
	std::string next();

	//Accessors
	void setIdentifier(std::string);
	void setDescription(std::string);
	void setCondition(std::string);
	std::string getIdentifier();
	END_CONDITION getCondition();
	void addNeighbor(std::string, std::string);

protected:
	std::string transition;
	END_CONDITION condition;
	std::string identifier;
	std::string description;
	std::map<std::string, std::string> neighbors;
};

#endif // !ROOM_H
