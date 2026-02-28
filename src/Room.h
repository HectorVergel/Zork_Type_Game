#ifndef ROOM_H
#define ROOM_H

#include "Entity.h"
#include <string>
#include "Exit.h"

class Room : public Entity
{
public:
	Room(const std::string& aName, const std::string& aDescription);
	~Room() override = default;

	void Look();
	Exit* GetExit(const std::string& aDirection);

private:
	std::list<Exit*> mExits;
};

#endif