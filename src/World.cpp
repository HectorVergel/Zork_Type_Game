#include "World.h"
#include "Exit.h"
#include "Utils.h"

World::World() : 
	mPlayer(nullptr)
{
	CreateWorld();
}

World::~World()
{
	SAFE_DELETE_VECTOR(mRooms);
	SAFE_DELETE(mPlayer);
}

Player* World::GetPlayer()
{
	return mPlayer;
}

void World::CreateWorld()
{
	// -- ROOMS --

	Room* Forest = new Room("Forest", "It is surrounded by big trees.", false);
	
	Room* Cave = new Room("Cave", "It is cold and you barely can see.", false);
	Room* HidedRoom = new Room("Hided Room", "An small and rounded room", false);

	Room* Camp = new Room("Camp", "It has a recent campfire and some bagpacks", false);
	Room* Tent = new Room("Tent", "There are two sleeping bags, everything is messy", false);
	Room* Bedroom = new Room("Cave Bedroom", "Someone sleeps in here...", true);

	mRooms.push_back(Forest);
	mRooms.push_back(Cave);
	mRooms.push_back(HidedRoom);
	mRooms.push_back(Camp);
	mRooms.push_back(Tent);


	// -- EXITS --

	Exit* ForestToCamp = new Exit(WEST, Forest, Camp);
	Exit* ForestToCave = new Exit(EAST, Forest, Cave);
	Exit* CampToTent = new Exit(NORTH, Camp, Tent);
	Exit* CampToForest = new Exit(EAST, Camp, Forest);
	Exit* TentToCamp = new Exit(SOUTH, Tent, Camp);
	Exit* CaveToHidedRoom = new Exit(EAST, Cave, HidedRoom);
	Exit* CaveToBedroom = new Exit(SOUTH, Cave, Bedroom);
	Exit* CaveToForest = new Exit(WEST, Cave, Forest);
	Exit* HidedRoomToCave = new Exit(WEST, HidedRoom, Cave);
	Exit* BedroomToCave = new Exit(NORTH, Bedroom, Cave);

	// -- ITEMS --

	Item* Key = new Item("Key", "It might open a closed door.", HidedRoom);
	Item* Bagpack = new Item("Bagpack", "You can use it to store other items", Tent, 4);

	// -- PLAYER --

	mPlayer = new Player("Hector", "A brave adventurer", Forest);

}
