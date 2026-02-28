#include "Entity.h"
#include "Utils.h"

Entity::Entity(const std::string& aName, const std::string& aDescription, Entity* aParent) :
	mName(aName),
	mDescription(aDescription),
	mParent(aParent)
{
	if(mParent != nullptr)
	{
		mParent->mContains.push_back(this);
	}

	mType = ENTITY;
}

Entity::~Entity()
{
	SAFE_DELETE_VECTOR(mContains);
}

const std::string Entity::GetName()
{
	return mName;
}

const EntityType Entity::GetType()
{
	return mType;
}
