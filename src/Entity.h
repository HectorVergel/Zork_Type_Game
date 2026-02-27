#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <vector>

enum EntityType
{
	ENTITY
};

class Entity
{
public:
	Entity(const std::string aName, const std::string aDescription, Entity* aParent);
	virtual ~Entity();
	virtual void Update() = 0;

private:
	EntityType mType;
	std::string mName;
	std::string mDescription;
	std::vector<Entity*> mContains;
	Entity* mParent;
};
#endif

