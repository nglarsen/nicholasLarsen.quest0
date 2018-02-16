#include "Room.h"
#include <sstream>

Room::Room()
{
	identifier = "start";
	description = "description of start room.";
	transition = "";
	condition = NONE;
}


Room::Room(TiXmlElement* pRoomElem)
{
	Initialize(pRoomElem);
}

Room::~Room()
{
	NULL;
}

bool Room::Initialize(TiXmlElement* xml)
{
	/***************************************************************
	  Reference: www.grinninglizard.com/tinyxmldocs/tutorial0.html
	***************************************************************/
	this->setDescription(xml->Attribute("description"));
	this->setIdentifier(xml->Attribute("name"));
	this->setCondition(xml->Attribute("condition"));
	TiXmlElement* neighborElement = xml->FirstChildElement("Neighbor");

	while (neighborElement)
	{
		addNeighbor(neighborElement->Attribute("transition"), neighborElement->Attribute("target"));
		neighborElement = neighborElement->NextSiblingElement();
	}
	if (neighbors.size() > 0)
		return true;
	else
		return false;

}

bool Room::finish()
{


	if (this->condition == NONE)
		return false;
	else
		return true;
}

std::string Room::next()
{
	return neighbors.find(transition)->second;
}

void Room::setDescription(std::string x)
{
	this->description = x;
}

void Room::setIdentifier(std::string x)
{
	this->identifier = x;
}

void Room::setCondition(std::string x)
{
	/**********************************************************************************
		REFERENCE: https://www.geeksforgeeks.org/converting-strings-numbers-cc/
	**********************************************************************************/
	std::stringstream geek(x);
	int stringToEndCondition = 0;
	geek >> stringToEndCondition;

	this->condition = (END_CONDITION)stringToEndCondition;
}

END_CONDITION Room::getCondition()
{
	return this->condition;
}

std::string Room::getIdentifier()
{
	return this->identifier;
}

void Room::addNeighbor(std::string trans, std::string target)
{
	neighbors.insert(std::pair<std::string, std::string>(trans, target));
}