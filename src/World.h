#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "Entity.h"

class World 
{
public:
	World();
private:
	std::vector<Entity*> mEntities;
};

#endif
