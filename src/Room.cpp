#include "Room.h"
#include <iostream>

Room::Room(const std::string& aName, const std::string& aDescription) : 
	Entity(aName, aDescription, nullptr)
{
	mType = ROOM;
}

void Room::Look()
{
	std::cout << mName << std::endl;
	std::cout << mDescription << std::endl;
	
	std::cout << "From this room you can see: " << std::endl;

	for(const auto& Exit : mExits)
	{
		std::cout << Exit->GetDestination()->GetName() + " at " + Exit->GetDirectionAsString();
	}
	
	for(const auto& Object : mContains)
	{
		Object->DescribeInRoom();
	}
}

Exit* Room::GetExit(const std::string& aDirection)
{
	return nullptr;
}
