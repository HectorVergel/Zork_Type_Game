#include "Exit.h"

Exit::Exit(const Direction& aDirection,  Room* aOrigin, Room* aDestination) :
	mOrigin(aOrigin),
	mDestination(aDestination),
	mDirection(aDirection)
{
	mOrigin->AddExit(this);
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
	case NORTH:
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
