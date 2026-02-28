#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <list>

enum EntityType
{
	ENTITY,
	ROOM,
	EXIT,
	ITEM,
	CREATURE
};

class Entity
{
public:
	Entity(const std::string& aName, const std::string& aDescription, Entity* aParent);
	virtual ~Entity();
	virtual void Update() = 0;
	virtual void DescribeInRoom(){}

	const EntityType GetType();
	const std::string GetName();


protected:
	EntityType mType;
	std::string mName;
	std::string mDescription;
	std::list<Entity*> mContains;
	Entity* mParent;
};
#endif

