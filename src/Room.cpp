#include "Room.h"
#include <iostream>

Room::Room(const std::string& aName, const std::string& aDescription, const bool aLocked) : 
	Entity(aName, aDescription, nullptr),
	mLocked(aLocked)
{
}

void Room::Update()
{
}

void Room::Describe() const
{
	std::cout << mName << std::endl;
	std::cout << mDescription << std::endl;
}

void Room::Look()
{	
	std::cout << "From this room you can see: " << std::endl;

	if (!mExits.empty())
	{
		std::cout << "\nExits:\n";
		for (const auto& Exit : mExits)
		{
			std::cout << " - " << Exit->GetDirectionAsString() << std::endl;
		}
	}

	if(!mContains.empty())
	{
		for (const auto& Object : mContains)
		{
			Object->Describe();
		}
	}
}

Exit* Room::GetExit(const std::string& aDirection)
{
	for(const auto& Exit : mExits)
	{
		const std::string ExitDirectionName = Exit->GetDirectionAsString();
		if(ExitDirectionName.compare(aDirection) == 0) 
		{
			return Exit;
		}
	}
}

void Room::AddExit(Exit* aExit)
{
	mExits.push_back(aExit);
}
