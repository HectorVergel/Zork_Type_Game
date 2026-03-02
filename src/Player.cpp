#include <iostream>
#include "Player.h"
#include "Exit.h"
#include "NPC.h"

bool Player::HasItem(const std::list<Entity*>& aContainer, const std::string& aItem)
{
	for (const auto& Object : aContainer)
	{
		if (Object->IsStorage())
		{
			bool FoundItem = HasItem(Object->GetContains(), aItem);
			if(!FoundItem)
			{
				continue;
			}
			else
			{
				return FoundItem;
			}
		}
		else
		{
			if (Object->GetName().compare(aItem) == 0)
			{
				return true;
			}
		}
	}
	return false;
}

Player::Player(const std::string& aName, const std::string& aDescription, Room* aStartingRoom) :
	Entity(aName, aDescription, aStartingRoom)
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

void Player::Drop(const std::string& aItemName)
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

void Player::Move(const std::string& aDirection)
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

	if (Exit->GetDestination()->GetIsLocked() && !HasItem(mContains, "Key"))
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

void Player::Take(const std::string& aItemName)
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

void Player::Store(const std::string& aItemToStore, const std::string& aItemStorage)
{
	Entity* ItemToStore = Find(aItemToStore);
	
	if(ItemToStore == nullptr)
	{
		std::cout << "You don't have that item to store." << std::endl;
		return;
	}

	Entity* ItemStorage = Find(aItemStorage);

	if(ItemStorage == nullptr)
	{
		std::cout << "You don't have that item as an storage" << std::endl;
		return;
	}

	Remove(ItemToStore);

	if(ItemStorage->Add(ItemToStore))
	{
		std::cout << "You stored " << ItemToStore->GetName() << " in " << ItemStorage->GetName() << std::endl;
	}
	else
	{
		std::cout << "You stored don't have enough space in " << ItemStorage->GetName() << std::endl;
	}
	
}

void Player::Talk(const std::string& aName)
{
	Room* CurrentRoom = GetCurrentRoom();

	if(CurrentRoom == nullptr)
	{
		return;
	}

	NPC* CharacterNPC = dynamic_cast<NPC*>(CurrentRoom->Find(aName));

	if(CharacterNPC == nullptr)
	{
		std::cout << "There is no one in here with that name" << std::endl;
		return;
	}

	CharacterNPC->Dialog(HasItem(mContains, CharacterNPC->GetQuestItem()));
}

Room* Player::GetCurrentRoom() const
{
	return static_cast<Room*>(mParent);
}
