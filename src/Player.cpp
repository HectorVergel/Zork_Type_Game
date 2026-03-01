#include <iostream>
#include "Player.h"

Player::Player(const std::string& aName, const std::string& aDescription, Room* aStartingRoom) : 
	Entity(aName, aDescription, aStartingRoom)
{
}

void Player::Update()
{
}

void Player::Describe() const
{
}

void Player::Look()
{
	if(Room* Room = GetCurrentRoom())
	{
		Room->Look();
	}
}

void Player::Drop(std::string& aItemName)
{
}

void Player::Move(std::string& aDirection)
{
	Room* CurrentRoom = GetCurrentRoom();

	if (CurrentRoom == nullptr)
	{
		return;
	}

	Exit* Exit = CurrentRoom->GetExit(aDirection);

	if (Exit == nullptr) 
	{
		std::cout << "You can't go that way." << std::endl;
		return;
	}

	Room* Destination = Exit->GetDestination();

	if(Destination == nullptr)
	{
		return;
	}

	std::cout << "You move to " << Destination->GetName() << std::endl;
	Destination->Look();
}

void Player::Take(std::string& aItemName)
{
}

Room* Player::GetCurrentRoom() const
{
	return static_cast<Room*>(mParent);
}
