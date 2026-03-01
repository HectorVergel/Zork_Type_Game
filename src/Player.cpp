#include <iostream>
#include "Player.h"
#include "Exit.h"

bool Player::HasKey()
{
	auto Iterator = std::find_if(mContains.begin(), mContains.end(), [](Entity* Entity) { return Entity->GetName().compare("key"); });
	bool HasKey = Iterator != mContains.end();
	return HasKey;
}

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
	Entity* Item = Find(aItemName);

	if(Item == nullptr)
	{
		std::cout << "You don't have that" << std::endl;
		return;
	}

	Remove(Item);
	GetCurrentRoom()->Add(Item);

	std::cout << "You dropped " << Item->GetName() << std::endl;
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

	if (Exit->GetDestination()->GetIsLocked() && !HasKey())
	{
		std::cout << "You can't go that way, it's locked. Find a key." << std::endl;
		return;
	}

	Room* Destination = Exit->GetDestination();

	if(Destination == nullptr)
	{
		return;
	}

	CurrentRoom->Remove(this);
	Destination->Add(this);

	std::cout << "You move to " << Destination->GetName() << std::endl;
	Destination->Look();
}

void Player::Take(std::string& aItemName)
{
	Room* Room = GetCurrentRoom();

	Entity* Item = Room->Find(aItemName);

	if(Item == nullptr)
	{
		std::cout << "That item is not here" << std::endl;
		return;
	}

	Room->Remove(Item);
	Add(Item);

	std::cout << "You picked up " << Item->GetName() << std::endl;
}

Room* Player::GetCurrentRoom() const
{
	return static_cast<Room*>(mParent);
}
