#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "Entity.h"
#include "Player.h"
#include "Room.h"

class World 
{
public:
	World();
	~World();

	Player* GetPlayer();
private:

	void CreateWorld();

	std::vector<Room*> mRooms;
	Player* mPlayer;
};

#endif
