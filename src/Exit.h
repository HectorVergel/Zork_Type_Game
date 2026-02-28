#ifndef EXIT_H
#define EXIT_H

#include "Room.h"

enum Direction 
{
	NORD,
	SOUTH,
	WEST,
	EAST
};

class Exit 
{
public:
	Exit(const Direction& aDirection, Room* aDestination);
	Room* GetDestination() const;
	std::string GetDirectionAsString() const;

private:
	Room* mDestination;
	Direction mDirection;
};
#endif