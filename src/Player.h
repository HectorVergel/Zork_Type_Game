#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Entity.h"
#include "Room.h"
#include "Item.h"
#include "NPC.h"

class Player : public Entity
{
public:
	Player(const std::string& aName, const std::string& aDescription, Room* aStartingRoom);

	void Describe() const override;

	void Look();
	void Drop(std::string& aItemName);
	void Move(std::string& aDirection);
	void Take(std::string& aItemName);
	void Store(std::string& aItemToStore, std::string& aItemStorage);
	void Talk(std::string& aName);

	Room* GetCurrentRoom() const;

private:
	bool HasItem(const std::list<Entity*>& aContainer, const std::string& aItem);

};

#endif