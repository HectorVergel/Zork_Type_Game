#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Entity.h"
#include "Room.h"

class Player : public Entity
{
public:
	Player(const std::string& aName, const std::string& aDescription, Room* aStartingRoom);

	void Update() override;
	void Describe() const override;

	void Look();
	void Drop(std::string& aItemName);
	void Move(std::string& aDirection);
	void Take(std::string& aItemName);

	Room* GetCurrentRoom() const;
};

#endif