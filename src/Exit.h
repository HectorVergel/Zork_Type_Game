#ifndef EXIT_H
#define EXIT_H

#include "Room.h"

enum Direction 
{
	NORTH,
	SOUTH,
	WEST,
	EAST
};

class Exit 
{
public:
	Exit(const Direction& aDirection, Room* aOrigin, Room* aDestination);
	Room* GetDestination() const;
	std::string GetDirectionAsString() const;

private:
	Room* mOrigin;
	Room* mDestination;
	Direction mDirection;
};
#endif