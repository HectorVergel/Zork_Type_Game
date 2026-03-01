#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Entity.h"
#include "Room.h"
#include "Item.h"

class Player : public Entity
{
private:
	bool HasKey(const std::list<Entity*>& aContainer);

public:
	Player(const std::string& aName, const std::string& aDescription, Room* aStartingRoom);

	void Update() override;
	void Describe() const override;

	void Look();
	void Drop(std::string& aItemName);
	void Move(std::string& aDirection);
	void Take(std::string& aItemName);
	void Store(std::string& aItemToStore, std::string& aItemStorage);

	Room* GetCurrentRoom() const;
};

#endif