#include "Exit.h"

Exit::Exit(const Direction& aDirection, Room* aDestination) :
	mDestination(aDestination),
	mDirection(aDirection)
{
}

Room* Exit::GetDestination() const
{
	return mDestination;
}

std::string Exit::GetDirectionAsString() const
{
	std::string Direction = "";

	switch (mDirection)
	{
	case NORD:
		Direction = "North";
		break;

	case SOUTH:
		Direction = "South";

		break;
	case WEST:
		Direction = "West";

		break;
	case EAST:
		Direction = "East";

		break;
	default:
		break;
	}

}
